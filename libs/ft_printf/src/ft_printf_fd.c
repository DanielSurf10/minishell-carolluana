/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:07:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/20 20:13:11 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *str, ...)
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
		{
			ft_putchar_fd(str[i], fd);
			num_char++;
		}
		i++;
	}
	va_end(args);
	return (num_char);
}
