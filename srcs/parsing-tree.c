/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:53:50 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/12/27 20:30:07 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	build_branch(t_list *tkn_list, t_tree *pivot)
{
	pivot->sub_list = hunt_last_pipe(tkn_list);
	if (pivot->sub_list)
	{
		pivot->tkn_type = pivot->sub_list->token.type;
		pivot->sub_list->next->prev = NULL;
		pivot->right = build_root(pivot->sub_list->next);
		pivot->sub_list->prev->next = NULL;
		pivot->left = build_root(tkn_list);
		pivot->sub_list->next = NULL;
		pivot->sub_list->prev = NULL;
	}
	else
	{
		pivot->redir = hunt_redir(&tkn_list);
		pivot->sub_list = tkn_list;
		pivot->tkn_type = COMMAND;
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
			break ;
		}
		node = node->prev;
	}
	return (NULL);
}

t_redir	*hunt_redir(t_list	**tkn_list)
{
	t_list	*free_token;
	t_list	*tmp_token;
	t_list	*node;
	t_redir	*redir;

	node = *tkn_list;
	redir = NULL;
	while (node)
	{
		if (node->token.type >= REDIRECT_INPUT
			&& node->token.type <= REDIRECT_OUTPUT_APPEND)
		{
			free_token = node;
			ft_lst_add_back(&redir,
				ft_lst_new(node->next->token.lexeme, node->token.type));
			if (node->prev)
			{
				node->prev->next = node->next->next;
				tmp_token = node->next->next;
			}
			else
			{
				*tkn_list = node->next->next;
				tmp_token = *tkn_list;
			}
			if (node->next->next)
				node->next->next->prev = node->prev;
			free(free_token->next);
			free(free_token);
			node = tmp_token;
		}
		else
			node = node->next;
	}
	return (redir);
}
