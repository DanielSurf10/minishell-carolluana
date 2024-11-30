/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:15:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/29 18:25:42 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_key_name(char *key)
{
	int	i;

	i = 0;
	if (key[0] != '_' && !ft_isalpha(key[0]))
	{
		printf("export: not an identifier: %s\n", key);
		return (0);
	}
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			printf("export: not valid in this context: %s\n", key);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_getenv(char *arg, t_envp *env_list)
{
	t_envp	*temp;

	temp = env_list;
	while (temp)
	{
		if (ft_strcmp(arg, temp->key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

int	ft_check_key(char *arg, t_envp *env_list)
{
	t_envp	*temp;

	temp = env_list;
	while (temp)
	{
		if (ft_strcmp(arg, temp->key) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_arg(char	*arg)
{
	int	i;

	i = 0;
	if (arg == NULL)
		return (0);
	while (arg[i])
	{
		if (!ft_is_space(arg[i]))
			return (1);
		i++;
	}
	return (0);
}
