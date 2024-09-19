/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:27:55 by cshingai          #+#    #+#             */
/*   Updated: 2023/10/26 16:21:20 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int n, size_t x)
{
	size_t			index;
	unsigned char	*char_ptr;

	char_ptr = (unsigned char *) ptr;
	index = 0;
	while (index < x)
	{
		char_ptr[index] = (unsigned char)n;
		index++;
	}
	return (ptr);
}
