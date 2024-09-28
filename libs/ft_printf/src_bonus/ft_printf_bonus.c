/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:07 by cshingai          #+#    #+#             */
/*   Updated: 2024/01/11 17:09:04 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <limits.h>

int	print_format(const char *str, va_list args, int idx)
{
	if (str[idx] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[idx] == 'd' || str[idx] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[idx] == 'u')
		return (ft_putnbr_dec(va_arg(args, int)));
	else if (str[idx] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[idx] == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	else if (str[idx] == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 1));
	else if (str[idx] == 'p')
		return (ft_put_pointer(va_arg(args, unsigned long), 0));
	else if (str[idx] == '#' && (str[idx + 1] == 'x' || str[idx + 1] == 'X'))
		return (print_format_hash(va_arg(args, unsigned int), str[idx + 1]));
	else if ((str[idx] == ' ' || str[idx] == '+')
		&& (str[idx + 1] == 'd' || str[idx + 1] == 'i'))
		return (print_format_sign(va_arg(args, int), str[idx]));
	else if (str[idx] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	print_format_hash(unsigned long nbr, char type)
{
	int	count;

	count = 0;
	if (nbr != 0)
	{
		if (type == 'x')
			count += ft_putstr("0x");
		else if (type == 'X')
			count += ft_putstr("0X");
	}
	if (type == 'x')
		count += ft_putnbr_hex(nbr, 0);
	else if (type == 'X')
		count += ft_putnbr_hex(nbr, 1);
	return (count);
}

int	print_format_sign(int nbr, char sign)
{
	int	count;

	count = 0;
	if (nbr >= 0)
		count += ft_putchar(sign);
	count += ft_putnbr(nbr);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		num_char;
	va_list	args;

	i = 0;
	num_char = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			num_char += print_format(str, args, i + 1);
			if (str[i + 1] == '#' || str[i + 1] == ' ' || str[i + 1] == '+')
				i++;
			i++;
		}
		else
			num_char += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (num_char);
}
