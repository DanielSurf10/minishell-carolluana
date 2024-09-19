/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:58:25 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/02 20:42:07 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *str1, const void *str2, size_t n)
{
	size_t				index;
	unsigned const char	*char_str1;
	unsigned const char	*char_str2;

	index = 0;
	char_str1 = str1;
	char_str2 = str2;
	if (!str1 && !str2)
		return (0);
	if (n == 0)
		return (0);
	while (index < n - 1)
	{
		if (char_str1[index] == char_str2[index])
			index++;
		else
			return (char_str1[index] - char_str2[index]);
	}
	return (char_str1[index] - char_str2[index]);
}
