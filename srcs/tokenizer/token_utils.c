/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:38:29 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/09 17:39:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_space(char c)
{
	if (c == 32 || c == 9 || c == 11 || c == 13)
		return (1);
	return (0);
}

int	is_metachar(char c)
{
	if (c == '|')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else
		return (0);
}

void	state_requires_backtrack(t_tkn_data *tkn_data, int	*i)
{
	if (tkn_data->state == 32 || tkn_data->state == 42 || tkn_data->state == 53)
	{
		tkn_data->lex_len = tkn_data->lex_len - 1;
		*i = (*i) - 1;
	}
}

void	token_clear_list(t_list **token_list)
{
	t_list	*aux;

	while (*token_list)
	{
		aux = *token_list;
		*token_list = (*token_list)->next;
		free(aux->token.lexeme);
		free(aux);
	}
}
