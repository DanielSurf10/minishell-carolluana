/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:26:50 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:35:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, size_t n)
{
	size_t	i;
	char	char_c;
	char	*char_str;

	i = 0;
	char_c = c;
	char_str = (char *) str;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)char_str[i] == (unsigned char)char_c)
			return (&char_str[i]);
		i++;
	}
	if (!c)
		return (str);
	return (NULL);
}
