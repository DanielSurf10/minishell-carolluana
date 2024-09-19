/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:09:32 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:34:27 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_nbr(int n)
{
	int	lenght;

	lenght = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		lenght++;
	while (n)
	{
		lenght++;
		n /= 10;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long long	number;

	len = count_nbr(n);
	str = (char *)malloc (sizeof(char) * (len + 1));
	number = n;
	if (!str)
		return (0);
	if (number < 0)
		number = -number;
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	if (number == 0)
		str[0] = '0';
	while (number != 0)
	{
		len--;
		str[len] = (number % 10) + '0';
		number = number / 10;
	}
	return (str);
}
