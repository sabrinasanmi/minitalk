/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:24:20 by sabsanto          #+#    #+#             */
/*   Updated: 2025/02/08 02:26:55 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putuphex(unsigned long nbr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_putuphex(nbr / 16);
	count += write(1, &hex[nbr % 16], 1);
	return (count);
}
