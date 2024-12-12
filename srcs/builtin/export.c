/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:59:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/11 21:42:17 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	export_new_var(char **new_var, t_envp **env_list)
{
	t_envp	*new_env_var;
	int		valid;

	new_env_var = env_create_node();
	if (!new_env_var)
		return (1);
	new_env_var->key = ft_strdup(new_var[0]);
	if (new_var[1])
		new_env_var->value = ft_strdup(new_var[1]);
	else
		new_env_var->value = ft_strdup("");
	valid = check_key_name(new_env_var->key, "export");
	if (valid == 0)
		add_node_to_list(env_list, new_env_var);
	return (valid);
}

void	change_env_value(char *key, char *value, t_envp **env_list)
{
	t_envp	*temp;

	temp = *env_list;
	while (temp && ft_strcmp(temp->key, key) != 0)
			temp = temp->next;
	free(temp->value);
	if (value == NULL)
		value = "";
	temp->value = ft_strdup(value);
}

void	order_env_list(t_envp **env_list)
{
	char	*temp_key;
	char	*temp_value;
	t_envp	*temp;

	temp = *env_list;
	while (temp && temp->next)
	{
		if (ft_strcmp(temp->key, temp->next->key) > 0)
		{
			temp_key = temp->key;
			temp_value = temp->value;
			temp->key = temp->next->key;
			temp->value = temp->next->value;
			temp->next->key = temp_key;
			temp->next->value = temp_value;
			order_env_list(env_list);
		}
		temp = temp->next;
	}
}

// int	export(char **arg, t_envp **env_list)
// {
// 	char	**new_var;
// 	int		status_command;
// 	int		i;

// 	status_command = 0;
// 	i = -1;
// 	if (*arg == NULL)
// 		export_no_args(env_list);
// 	while (arg[++i])
// 	{
// 		if (is_equal(arg[i], "export") == 1)
// 		{
// 			status_command = 1;
// 			i++;
// 		}
// 		new_var = new_var_split(arg[i]);
// 		if (key_exist(new_var[0], *env_list) == 1)
// 			change_env_value(new_var[0], new_var[1], env_list);
// 		else
// 			status_command = export_new_var(new_var, env_list);
// 		ft_free_split(new_var);
// 	}
// 	return (status_command);
// }

int	export_no_args(t_envp **env_list)
{
	order_env_list(env_list);
	print_env_list(*env_list);
	return (0);
}

int	export(char **arg, t_envp **env_list)
{
	int		status_command;
	int		i;

	status_command = 0;
	i = -1;
	if (*arg == NULL)
		export_no_args(env_list);
	while (arg[++i])
	{
		if (is_equal(arg[i], "export") == 1)
		{
			status_command = 1;
			i++;
		}
		status_command = insert_var(arg[i], env_list);
	}
	return (status_command);
}

int	insert_var(char *arg, t_envp **env_list)
{
	char	**new_env;
	int		status_command;

	new_env = NULL;
	status_command = 0;
	if (!arg)
		return (0);
	new_env = get_key_value(arg, new_env);
	if (key_exist(new_env[0], *env_list))
		change_env_value(new_env[0], new_env[1], env_list);
	else
		status_command = export_new_var(new_env, env_list);
	ft_free_split(new_env);
	return (status_command);
}

char **get_key_value(char *arg, char **dest)
{
	int		i;
	int		j;

	if (!arg)
		return (NULL);
	dest = calloc(ft_strlen(arg), sizeof(char *));
	i = 0;
	j = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	dest[0] = calloc(i + 1, sizeof(char));
	i = 0;
	while (arg[i] && arg[i] != '=')
		dest[0][j++] = arg[i++];
	dest[1] = calloc(ft_strlen(arg) - i, sizeof(char));
	i++;
	j = 0;
	while (arg[i])
		dest[1][j++] = arg[i++];
	return (dest);
}
