/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:51:46 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:44:29 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == (unsigned char)c)
		{
			return ((char *)&str[index]);
		}
		index++;
	}
	if ((unsigned char)c == str[index])
		return ((char *) &str[index]);
	return (0);
}
