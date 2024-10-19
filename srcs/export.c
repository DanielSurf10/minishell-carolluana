/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:59:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/18 21:54:30 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// verificar se a variavel existe no env
// Criar variável jogar no env
// pegar a varival e jogar na lista
void	export_new_var(char	*arg, t_envp **env_list)
{
	char	**new_var;
	t_envp	*new_env_var;
	if (!ft_getenv(arg, *env_list))
	{
		new_var = new_var_split(arg);
		new_env_var = env_create_node();
		new_env_var->key = new_var[0];
		new_env_var->value = new_var[1];
		add_node_to_list(env_list, new_env_var);
	}
	return ;
}

char	*ft_getenv(char *arg, t_envp *env_list)
{
	t_envp	*temp;
	temp = env_list;
	while (temp)
	{
		if (arg == temp->key)
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

void	export(char *arg, t_envp *env_list)
{
	char	*var;
	char	**new_var;
	t_envp	*temp;

	new_var = new_var_split(arg);
	var = ft_getenv(new_var[0], env_list);
	temp = env_list;
	if (var != NULL)
	{
		while (temp && temp->key != new_var[0])
			temp = temp->next;
		temp->value = new_var[1];
	}
	else
		export_new_var(arg, &env_list);
}

// void	change_env_value(char *arg, t_envp **env_list)
// {

// }
