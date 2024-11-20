/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:36:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/20 17:26:41 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_envp	*env_create_node(void)
{
	t_envp	*new_node;

	new_node = malloc(sizeof(t_envp));
	if (!new_node)
		return (NULL);
	new_node->key = NULL;
	new_node->value = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_list(t_envp **head, t_envp *node)
{
	t_envp	*temp;

	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

t_envp	*node_from_environ(char *environ)
{
	t_envp	*node;
	char	**split_environ;

	split_environ = ft_split(environ, '=');
	node = env_create_node();
	if (split_environ[0])
		node->key = ft_strdup(split_environ[0]);
	if (split_environ[1])
		node->value = ft_strdup(split_environ[1]);
	ft_free_split(split_environ);
	return (node);
}

t_envp	*create_env_list(char **environ)
{
	t_envp	*envp_list;
	t_envp	*head;
	int		i;

	head = NULL;
	i = 0;
	while (environ[i])
	{
		envp_list = node_from_environ(environ[i]);
		if (!envp_list)
		{
			free_env_list(head);
			return (NULL);
		}
		add_node_to_list(&head, envp_list);
		i++;
	}
	return (head);
}
