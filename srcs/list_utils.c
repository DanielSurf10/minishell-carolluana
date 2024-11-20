/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:26:31 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/11/08 18:37:55 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_list	*token_create_node(char *lexeme, int token_type)
{
	t_list	*new_token;

	new_token = malloc(sizeof(t_list));
	new_token->token.lexeme = lexeme;
	new_token->token.type = token_type;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

void	token_add_to_list(t_list **token_list, char *lexeme, int token_type)
{
	t_list	*new_token;
	t_list	*last_node;

	// printf("teste 1\n");
	last_node = *token_list;
	new_token = token_create_node(lexeme, token_type);
	while (last_node && last_node->next)
		last_node = last_node->next;
	if (last_node)
	{
		last_node->next = new_token;
		last_node->next->prev = last_node;
	}
	else
		*token_list = new_token;
	// printf("lastnode type: %d\n", last_node->token.type);
	// printf("type: %d lexema: %s\n", (*token_list)->token.type, (*token_list)->token.lexeme);
	// printf("teste 2");
}

void	free_list(t_list **token_list)
{
	t_list	*aux1;
	t_list	*aux2;

	if (token_list)
	{
		aux1 = *token_list;
		while (aux1)
		{
			aux2 = aux1->next;
			if (aux1->token.lexeme)
				free(aux1->token.lexeme);
			free(aux1);
			aux1 = aux2;
		}
		*token_list = NULL;
	}
}
void	*free_tree(t_tree **tree)
{
	if (*tree == NULL)
		return (NULL);
	if ((*tree)->right)
		free_tree(&(*tree)->right);
	if ((*tree)->left)
		free_tree(&(*tree)->left);
	if ((*tree)->sub_list)
		free_list(&(*tree)->sub_list);
	free(*tree);
	*tree = NULL;
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