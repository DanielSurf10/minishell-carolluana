/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:15:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/11 19:46:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_key_name(char *key, char *origin)
{
	int	i;

	i = 0;
	if (key[0] != '_' && !ft_isalpha(key[0]))
	{
		printf("minishell:%s: not a valid identifier: `%s'\n", origin, key);
		return (0);
	}
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			printf("minishell:%s: not a valid identifier: `%s'\n",
				origin, key);
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

int	key_exist(char *arg, t_envp *env_list)
{
	t_envp	*temp;

	temp = env_list;
	if (!arg)
		return (0);
	while (temp)
	{
		if (ft_strcmp(arg, temp->key) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_arg(char *arg)
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

int	is_equal(char *arg, char *origin)
{
	if (*arg == '=')
	{
		printf("minishell:%s: not a valid identifier: `%s'\n", origin, arg);
		return (1);
	}
	else
		return (0);
}
