/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:59:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/22 21:29:27 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// verificar se a variavel existe no env
// Criar variável jogar no env
// pegar a varival e jogar na lista
void	export_new_var(char **new_var, t_envp **env_list)
{
	t_envp	*new_env_var;

	new_env_var = env_create_node();
	new_env_var->key = new_var[0];
	new_env_var->value = new_var[1];
	add_node_to_list(env_list, new_env_var);
	return ;
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

char	**new_var_split(char *arg)
{
	char **new_var;
	if (!arg)
		return (NULL);
	else
		new_var = ft_split(arg, '=');
	return (new_var);
}

void	change_env_value(char **new_var, t_envp **env_list)
{
	t_envp	*temp;

	temp = *env_list;
	while (temp && ft_strcmp(temp->key, new_var[0]) != 0)
			temp = temp->next;
	free(temp->value);
	temp->value = ft_strdup(new_var[1]);
}

void	export(char *arg, t_envp **env_list)
{
	char	*var;
	char	**new_var;
	t_envp	*temp;

	if (arg == NULL)
		return (print_env_list(*env_list));
	new_var = new_var_split(arg);
	var = ft_getenv(new_var[0], *env_list);
	temp = *env_list;
	if (var != NULL)
		change_env_value(new_var, env_list);
	else
		export_new_var(new_var, env_list);
}

void	sort_env_list(t_envp **env_list)
{
	char	*temp_key;
	char	*temp_value;

	t_envp	*temp;
	
}
