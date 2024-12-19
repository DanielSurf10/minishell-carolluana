/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:10:30 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/19 18:08:45 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(char *str)
{
	int			index;
	int			sign;
	long long	number;

	index = 0;
	number = 0;
	sign = 1;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-')
	{
		sign *= -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
	{
		number = (number * 10) + (str[index] - '0');
		index++;
	}
	return (number * sign);
}
