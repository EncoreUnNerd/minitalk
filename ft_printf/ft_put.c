/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:17:37 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/29 18:27:13 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		i += ft_putstr("(null)");
	else
	{
		while (s[i])
			i++;
		write(1, s, i * sizeof(char));
		return (i);
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_putnbr(int n)
{
	int	res;

	res = 0;
	if (n < -9 || n > 9)
		res += ft_putnbr(n / 10);
	if (n < 0)
	{
		if (n >= -9)
			res += ft_putchar('-');
		res += ft_putchar('0' - (n % 10));
	}
	else
		res += ft_putchar('0' + (n % 10));
	return (res);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	res;

	res = 0;
	if (n > 9)
		res += ft_putnbr_unsigned(n / 10);
	res += ft_putchar('0' + (n % 10));
	return (res);
}
