/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:46:05 by sabsanto          #+#    #+#             */
/*   Updated: 2025/02/25 20:34:19 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack_received = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(pid_t server_pid, char c)
{
	int	bit;
	int	signal;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(server_pid, signal) == -1)
		{
			perror("Error sending signal");
			exit(1);
		}
		bit++;
		while (!g_ack_received)
			usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	int		i;

	if (argc != 3)
	{
		write(2, "Usage: ./client <server PID> <mesage>\n", 42);
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	signal(SIGUSR1, handle_ack);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, '\0');
	return (0);
}
