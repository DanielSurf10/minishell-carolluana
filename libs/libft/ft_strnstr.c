/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:10:15 by cshingai          #+#    #+#             */
/*   Updated: 2023/10/23 13:31:11 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *sm, size_t n)
{
	size_t	i_big;
	size_t	i_sm;

	i_big = 0;
	i_sm = 0;
	if (sm[0] == '\0')
		return (big);
	while (big[i_big] && i_big < n)
	{
		if (big[i_big] == sm[i_sm])
		{
			while ((big[i_big + i_sm] == sm[i_sm]) && (
					sm[i_sm]) && i_big + i_sm < n)
				i_sm++;
			if (sm[i_sm] == '\0')
				return (&big[i_big]);
			i_sm = 0;
		}
		i_big++;
	}
	return (0);
}
