/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:22:40 by sabsanto          #+#    #+#             */
/*   Updated: 2025/02/08 02:26:57 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex(unsigned long nbr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_puthex(nbr / 16);
	count += write(1, &hex[nbr % 16], 1);
	return (count);
}
