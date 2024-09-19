/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:24:51 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:42:36 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t_string;
	char	*new_string;
	size_t	index;
	size_t	last;

	index = 0;
	if (!s1)
		return (NULL);
	while (s1[index] && ft_strchr((char *)set, s1[index]))
	{
		index++;
	}
	if (!s1[index])
		return (ft_strdup(""));
	t_string = (char *) s1 + index;
	last = ft_strlen(t_string) - 1;
	while (t_string[last] && ft_strrchr((char *)set, t_string[last]))
	{
		last--;
	}
	new_string = ft_substr(t_string, 0, last + 1);
	return (new_string);
}
