/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:31:39 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/13 17:33:53 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**handle_state(char *str, t_minishell *shell, char **result)
{
	if (*result == NULL)
	{
		*result = ft_calloc(1, sizeof (char));
		(*result)[0] = '\0';
	}
	if (*str == '?')
		*result = ft_strjoin(*result, ft_itoa(shell->status));
	return (result);
}
