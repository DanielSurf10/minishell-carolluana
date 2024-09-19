/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:46:24 by cshingai          #+#    #+#             */
/*   Updated: 2023/11/07 14:42:43 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	index;
	size_t	i_sub;
	size_t	s_len;

	index = 0;
	i_sub = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub_s = (char *)malloc ((len + 1) * sizeof(*s));
	if (!sub_s)
		return (NULL);
	while (index < len && s[index + start])
	{
		sub_s[i_sub] = s[index + start];
		i_sub++;
		index++;
	}
	sub_s[i_sub] = '\0';
	return (sub_s);
}
