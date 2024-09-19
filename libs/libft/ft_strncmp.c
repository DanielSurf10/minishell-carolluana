/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:16:45 by cshingai          #+#    #+#             */
/*   Updated: 2023/10/26 16:15:29 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n - 1 && (str1[index] == str2[index])
		&& str1[index] && str2[index])
	{
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
