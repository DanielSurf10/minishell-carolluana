/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:49:59 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/24 14:07:13 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_redir	*ft_lst_new(char *file, int rd_type)
{
	t_redir	*new_node;

	new_node = ft_calloc(1, sizeof(t_redir));
	if (!new_node)
		return (NULL);
	new_node->file = file;
	new_node->rd_type = rd_type;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lst_add_back(t_redir **lst, t_redir *new)
{
	t_redir	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lst_last(*lst);
	last->next = new;
}

t_redir	*ft_lst_last(t_redir *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	free_redir(t_redir **redir)
{
	t_redir	*curr;

	while (*redir)
	{
		curr = *redir;
		*redir = (*redir)->next;
		free(curr->file);
		free(curr);
	}
	*redir = NULL;
}
