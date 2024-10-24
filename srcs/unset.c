/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:40:29 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/24 16:43:08 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	unset(char *arg, t_envp **env_list)
{
	char **key;

	key = ft_split(arg, '=');
	if (ft_getenv(key[0], *env_list) != NULL)
		remove_node_from_list(key[0], env_list);
	return ;
}

void	remove_node_from_list(char *arg, t_envp **env_list)
{
	t_envp	*temp;
	t_envp	*prev;

	temp = *env_list;
	prev = NULL;
	while (temp)
	{
		if (ft_strcmp(arg, temp->key) == 0)
		{
			if (prev == NULL)
				*env_list = temp->next;
			else
				prev->next = temp->next;
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;
	}
}
