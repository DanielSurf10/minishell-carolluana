/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:10:54 by cshingai          #+#    #+#             */
/*   Updated: 2023/10/19 17:50:02 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*char_str;
	size_t	index;

	index = 0;
	char_str = str;
	while (index < n)
	{
		char_str[index] = '\0';
		index++;
	}
}
