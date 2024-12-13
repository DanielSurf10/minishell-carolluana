/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:41:19 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/13 17:19:11 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	insert_var(char *arg, t_envp **env_list)
{
	char	**new_env;
	int		status_command;

	new_env = NULL;
	status_command = 0;
	if (!arg || !env_list)
		return (0);
	new_env = get_key_value(arg, new_env);
	if (!new_env || !new_env[0])
	{
		ft_free_split(new_env);
		return (1);
	}
	status_command = check_key_name(new_env[0], "export");
	if (status_command == 0)
	{
		if (key_exist(new_env[0], *env_list))
			change_env_value(new_env[0], new_env[1], env_list);
		else
			status_command = export_new_var(new_env, env_list);
	}
	ft_free_split(new_env);
	return (status_command);
}

char	**get_key_value(char *arg, char **dest)
{
	int	i;
	int	j;

	if (!arg)
		return (NULL);
	dest = calloc(3, sizeof(char *));
	i = 0;
	j = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	dest[0] = calloc(i + 1, sizeof(char));
	i = 0;
	while (arg[i] && arg[i] != '=')
		dest[0][j++] = arg[i++];
	dest[0][j] = '\0';
	dest[1] = calloc(ft_strlen(arg) - i + 1, sizeof(char));
	if (arg[i] == '=')
		i++;
	j = 0;
	while (arg[i])
		dest[1][j++] = arg[i++];
	dest[1][j] = '\0';
	dest[2] = NULL;
	return (dest);
}

char	**new_var_split(char *arg)
{
	char	**new_var;

	if (!arg)
		return (NULL);
	else
		new_var = ft_split(arg, '=');
	return (new_var);
}
