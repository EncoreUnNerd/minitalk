/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:57:59 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/29 19:20:19 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cases(char l, va_list args)
{
	int	res;

	res = 0;
	if (l == 's')
		res += ft_putstr(va_arg(args, char *));
	else if (l == 'd' || l == 'i')
		res += ft_putnbr(va_arg(args, int));
	else if (l == '%')
		res += ft_putchar('%');
	else if (l == 'c')
		res += ft_putchar(va_arg(args, int));
	else if (l == 'u')
		res += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (l == 'x' || l == 'X')
		res += ft_putnbr_base(va_arg(args, unsigned int), l);
	else if (l == 'p')
		res += ft_putnbr_base(va_arg(args, unsigned long), l);
	else
	{
		res += ft_putchar('%');
		res += ft_putchar(l);
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	if (!format)
		return (-1);
	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			res += ft_putchar(*format);
		else
		{
			format++;
			if (*format)
				res += cases(*format, args);
			else
				break ;
		}
		format++;
	}
	return (res);
}
