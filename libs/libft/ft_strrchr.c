/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:21:10 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/02 20:59:12 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, size_t n)
{
	size_t	b;

	b = ft_strlen(str);
	while (b + 1 != 0)
	{
		if (str[b] == (unsigned char) n)
			return (&str[b]);
		b--;
	}
	if (n == '\0')
	{
		return ((char *) &str[ft_strlen(str)]);
	}
	return (NULL);
}
