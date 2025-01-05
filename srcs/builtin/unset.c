/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:40:29 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/13 04:30:32 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	unset(char **arg, t_envp **env_list)
{
	// char	**new_var;
	// int		status_command;
	int		i;

	i = 0;
	// if (*arg == NULL)
	// 	unset_no_args();
	// if (*arg == NULL)
	// 	return (0);
	while (arg[i])
	{
		// if (is_equal(arg[i], "unset") == 1)
		// {
		// 	status_command = 1;
		// 	i++;
		// }
		// new_var = ft_split(arg[i], '=');
		// status_command = check_key_name(new_var[0], "unset");
		// if (!status_command)
		// {
		// 	if (key_exist(new_var[0], *env_list) == 1)
		// 		remove_node_from_list(new_var[0], env_list);
		// }
		// ft_free_split(new_var);
		remove_node_from_list(arg[i], env_list);
		i++;
	}
	return (0);
}

// int	unset_no_args(void)
// {
// 	ft_putendl_fd("unset: not enough arguments", STDERR_FILENO);
// 	return (1);
// }

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
			free(temp->key);
			free(temp->value);
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}
