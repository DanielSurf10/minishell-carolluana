/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:26:31 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/07 20:39:57 by lsouza-r         ###   ########.fr       */
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
	return (new_token);
}

void	token_add_to_list(t_list **token_list, char *lexeme, int token_type)
{
	t_list	*new_token;
	t_list	*last_node;

	printf("teste 1\n");
	last_node = *token_list;
	new_token = token_create_node(lexeme, token_type);
	while (last_node && last_node->next)
		last_node = last_node->next;
	if (last_node)
		last_node->next = new_token;
	else
		*token_list = new_token;
	// printf("lastnode type: %d\n", last_node->token.type);
	printf("type: %d lexema: %s\n", new_token->token.type, new_token->token.lexeme);
	printf("teste 2");
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

