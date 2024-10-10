/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:53:50 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/09 21:31:48 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// t_tree	*build_tree(t_list	*tkn_list)
// {
// 	t_tree	*tpm;
	
// 	tmp = hunt_pipe(tkn_list);
// }

t_list	*hunt_last_pipe(t_list	*tkn_list)
{
	t_list	*node;
	
	node = NULL;
	node = get_last_token(tkn_list);
	
	printf("pos node last: %d\n", node->pos);
	if (node && !node->prev && node->token.type == PIPE)
		return (node);
	while (node)
	{
		printf("pos node func: %d node type: %d\n", node->pos, node->token.type);
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
		printf("pos i: %d\n", tmp->pos);
	}
	tmp->pos = i;
	return (tmp);
}