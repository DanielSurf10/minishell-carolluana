/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:42:19 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:38:51 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	number;

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
