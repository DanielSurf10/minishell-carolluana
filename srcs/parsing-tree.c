/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:53:50 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/12 14:27:43 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	build_branch(t_list *tkn_list, t_tree *pivot)
{
	pivot->sub_list = hunt_last_pipe(tkn_list);
	if (pivot->sub_list)
	{	
		pivot->tkn_type = PIPE;
		pivot->sub_list->next->prev = NULL;
		pivot->sub_list->prev->next = NULL;
		pivot->right = build_root(pivot->sub_list->next);
		pivot->left = build_root(tkn_list);
		pivot->sub_list->next = NULL;
		pivot->sub_list->prev = NULL;
	}
	else
	{
		pivot->sub_list = tkn_list;
		pivot->left = NULL;
		pivot->right = NULL;
	}
}

t_tree	*build_root(t_list	*tkn_list)
{
	t_tree	*pivot;

	pivot = (t_tree *)ft_calloc(1, sizeof(t_tree));
	build_branch(tkn_list, pivot);
	return (pivot);
}

t_list	*hunt_last_pipe(t_list	*tkn_list)
{
	t_list	*node;
	
	node = NULL;
	node = get_last_token(tkn_list);
	if (node && !node->prev && node->token.type == PIPE)
		return (node);
	while (node)
	{
		if (node->token.type == PIPE)
		{
			return (node);
			break;
		}
		node = node->prev;
	}
	return (NULL);
}

t_list	*get_last_token(t_list	*tkn_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!tkn_list)
		return (NULL);
	tmp = tkn_list;
	while (tmp->next != NULL)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
	tmp->pos = i;
	return (tmp);
}