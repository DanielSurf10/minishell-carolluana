/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:49:59 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/13 17:50:49 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_redir	*ft_lstnew(char *file, int rd_type)
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

void	ft_lstadd_back(t_redir **lst, t_redir *new)
{
	t_redir	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_redir	*ft_lstlast(t_redir *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
