/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:33:01 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:23:56 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_element, size_t size)
{
	void	*temp;

	if ((size * n_element != 0) && (n_element * size) / size != n_element)
		return (0);
	temp = malloc (n_element * size);
	if (temp != 0)
		ft_memset(temp, 0, n_element * size);
	return (temp);
}
