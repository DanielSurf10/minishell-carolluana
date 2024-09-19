/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:03:41 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/02 20:43:50 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*char_src;
	char	*char_dest;

	i = n;
	char_dest = dest;
	char_src = src;
	if (!src && !dest)
		return (0);
	if (src > dest)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (i > 0)
		{
			char_dest[i - 1] = char_src[i - 1];
			i--;
		}
	}
	return (dest);
}
