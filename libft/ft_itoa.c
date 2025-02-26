/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:15:01 by sabsanto          #+#    #+#             */
/*   Updated: 2024/11/05 22:08:19 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_to_ascii(int n)
{
	if (n < 0)
		n = -n;
	return (n + '0');
}

static int	ft_numlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		digits_len;
	char	*num;

	sign = 0;
	digits_len = ft_numlen(n);
	if (n < 0)
		sign = 1;
	num = (char *)malloc((digits_len + sign + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[digits_len + sign] = '\0';
	if (sign)
		num[0] = '-';
	while (digits_len > 0)
	{
		num[digits_len + sign - 1] = ft_int_to_ascii(n % 10);
		n = n / 10;
		digits_len--;
	}
	return (num);
}
