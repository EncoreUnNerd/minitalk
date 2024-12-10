/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:35 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/29 18:48:09 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_base(char letter)
{
	if (letter == 'x' || letter == 'p')
		return ("0123456789abcdef");
	if (letter == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

static int	check_pointer(char letter, unsigned long nbr)
{
	if (letter == 'p' && nbr == 0)
		return (ft_putstr("(nil)"));
	if (letter != 'p' && nbr == 0)
		return (ft_putchar('0'));
	if (letter == 'p' && nbr != 0)
		return (ft_putstr("0x"));
	return (0);
}

int	ft_putnbr_base(unsigned long nbr, char letter)
{
	int		size_base;
	int		nbr_final[100];
	char	*base;
	int		i;
	int		res;

	i = 0;
	res = 0;
	res += check_pointer(letter, nbr);
	base = get_base(letter);
	size_base = 0;
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i++] = nbr % size_base;
		nbr = nbr / size_base;
	}
	while (--i >= 0)
		res += ft_putchar(base[nbr_final[i]]);
	return (res);
}
