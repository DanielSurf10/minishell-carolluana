/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:32:38 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:41:10 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	size_dest;
	size_t	size_src;

	i_dest = 0;
	i_src = 0;
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (n <= size_dest)
		return (size_src + n);
	while (dest[i_dest] && i_dest < n)
		i_dest++;
	while (src[i_src] && i_src + i_dest + 1 < n)
	{
		dest[i_dest + i_src] = src[i_src];
		i_src++;
	}
	if (i_dest + i_src < n)
	{
		dest[i_dest + i_src] = '\0';
	}
	return (size_dest + size_src);
}
