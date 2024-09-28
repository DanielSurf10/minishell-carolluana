/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:09:39 by cshingai          #+#    #+#             */
/*   Updated: 2024/01/10 18:52:43 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long nbr, int type)
{
	int	r;
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hex(nbr / 16, type);
		nbr %= 16;
	}
	if (nbr < 10)
		r = nbr + '0';
	else
	{
		if (type == 0)
			r = 'a' + nbr - 10;
		else
			r = 'A' + nbr - 10;
	}
	count += ft_putchar(r);
	return (count);
}

int	ft_put_pointer_nil(unsigned long nbr, int type)
{
	int				r;
	int				count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hex(nbr / 16, type);
		nbr %= 16;
	}
	if (nbr < 10)
		r = nbr + '0';
	else
	{
		if (type == 0)
			r = 'a' + nbr - 10;
		else
			r = 'A' + nbr - 10;
	}
	count += ft_putchar(r);
	return (count);
}

int	ft_put_pointer(unsigned long nbr, int type)
{
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	return (ft_putstr("0x") + ft_put_pointer_nil(nbr, type));
}
