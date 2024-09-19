/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:54:43 by cshingai          #+#    #+#             */
/*   Updated: 2023/10/31 15:46:53 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*str;

	index = 0;
	str = (char *)malloc (ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[ft_strlen(s)] = '\0';
	return (str);
}
