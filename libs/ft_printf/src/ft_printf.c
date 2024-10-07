/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:07 by cshingai          #+#    #+#             */
/*   Updated: 2024/01/11 17:13:31 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (str[idx] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		num_char;
	va_list	args;

	i = 0;
	num_char = 0;
	if (str == 0)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			num_char += print_format(str, args, i + 1);
			i++;
		}
		else
			num_char += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (num_char);
}
