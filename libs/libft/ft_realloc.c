/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:17:52 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/17 19:29:54 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **str, int size)
{
	char	**new_str;
	int		i;

	if (!str)
		return (NULL);
	new_str = ft_calloc(size + 1, sizeof (char *));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (size-- && str[i])
	{
		new_str[i] = ft_strdup(str[i]);
		i++;
	}
	free(str);
	return (new_str);
}
