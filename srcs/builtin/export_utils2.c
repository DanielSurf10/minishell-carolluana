/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:41:19 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/11 18:42:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**new_var_split(char *arg)
{
	char	**new_var;

	if (!arg)
		return (NULL);
	else
		new_var = ft_split(arg, '=');
	return (new_var);
}
