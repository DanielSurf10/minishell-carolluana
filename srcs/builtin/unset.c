/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:40:29 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/04 18:12:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	unset(char *arg, t_envp **env_list)
{
	char	**new_var;
	int		status_command;

	new_var = ft_split(arg, '=');
	status_command = check_key_name(new_var[0]);
	if (status_command)
	{
		if (ft_getenv(new_var[0], *env_list) != NULL)
			remove_node_from_list(new_var[0], env_list);
	}
	ft_free_split(new_var);
	return (status_command);
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
