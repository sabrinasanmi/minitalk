/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:45:40 by sabsanto          #+#    #+#             */
/*   Updated: 2025/02/25 19:06:28 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./ft_printf/include/ft_printf.h"

void	send_char(pid_t server_pid, char c);

void	send_message(pid_t server_pid, char *message);

void	handle_signal(int sig, siginfo_t *info, void *context);

#endif
