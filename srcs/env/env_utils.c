/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:47:38 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/26 19:16:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_nodes(t_envp *env_list)
{
	t_envp	*temp;
	int		nbr_nodes;

	nbr_nodes = 0;
	temp = env_list;
	while (temp)
	{
		nbr_nodes += 1;
		temp = temp->next;
	}
	return (nbr_nodes);
}

void	free_env_list(t_envp *env_list)
{
	t_envp	*temp;

	while (env_list)
	{
		temp = env_list;
		env_list = env_list->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

void	free_envp_str(char	**envp)
{
	int	i;

	i = 0;
	if (!envp)
		return ;
	while (envp[i])
	{
		if (envp[i])
			free(envp[i]);
		i++;
	}
	free(envp);
}

char	**list_to_str(t_envp *env_list)
{
	char	**envp;
	int		size;
	int		i;

	i = 0;
	size = count_nodes(env_list);
	envp = malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	while (env_list)
	{
		envp[i] = envp_str(env_list);
		env_list = env_list->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

char	*envp_str(t_envp *env_list)
{
	char	*envp_str;
	char	*temp;

	temp = NULL;
	if (!env_list->key)
		envp_str = NULL;
	else
	{
		temp = ft_strjoin(env_list->key, "=");
		if (env_list->value)
		{
			envp_str = ft_strjoin(temp, env_list->value);
			free(temp);
		}
		else
			envp_str = temp;
	}
	return (envp_str);
}
