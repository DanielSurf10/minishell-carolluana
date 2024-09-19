/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:49:28 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:40:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *c)
{
	char	*temp;
	int		index;
	int		len_c;

	index = 0;
	len_c = ft_strlen(c) + 1;
	temp = (char *)malloc (len_c * sizeof(char));
	if (temp == 0)
		return (0);
	while (c[index])
	{
		temp[index] = c[index];
		index++;
	}
	temp[index] = '\0';
	return (temp);
}
