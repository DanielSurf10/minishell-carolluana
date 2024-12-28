/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:09:36 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/28 19:57:31 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	valid_list(t_list *list)
{
	int	pipe_valid;
	int	redirect_valid;

	pipe_valid = valid_pipe(list);
	redirect_valid = valid_redirect(list);
	return (pipe_valid * redirect_valid);
}

int	valid_pipe(t_list *list)
{
	t_list	*aux;

	aux = list;
	while (aux)
	{
		if ((aux->token.type == PIPE && aux->next == NULL)
			|| (aux->token.type == PIPE && aux->prev == NULL))
		{
			ft_putstr_fd("Minihell: syntax error near unexpected token `|'\n",
				STDERR_FILENO);
			return (0);
		}
		else if (aux->token.type == PIPE && aux->next->token.type == PIPE)
		{
			ft_putstr_fd("This shell doesn't treat this case\n", STDERR_FILENO);
			return (0);
		}
		aux = aux->next;
	}
	return (1);
}

int	valid_redirect(t_list *list)
{
	t_list	*aux;

	aux = list;
	while (aux)
	{
		if (!check_syntax_error(aux))
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	check_syntax_error(t_list *aux)
{
	if ((aux->token.type >= REDIRECT_INPUT && aux->token.type <= REDIRECT_OUTPUT_APPEND)
		&& (aux->next == NULL))
	{
		ft_putstr_fd("Minihell: syntax error near unexpected token `newline'\n",
			STDERR_FILENO);
		return (0);
	}
	else if ((aux->token.type >= REDIRECT_INPUT && aux->token.type <= REDIRECT_OUTPUT_APPEND)
		&& aux->next->token.type != WORD)
	{
		ft_putstr_fd("Minihell: syntax error near unexpected token `>'\n",
			STDERR_FILENO);
		return (0);
	}
	// else if (aux->token.type == REDIRECT_HEREDOC && aux->next->token.type != WORD)
	// {
	// 	ft_putstr_fd("Minihell: syntax error near unexpected token `<'\n",
	// 		STDERR_FILENO);
	// 	return (0);
	// }
	// else if ((aux->token.type == REDIRECT_INPUT || aux->token.type == REDIRECT_OUTPUT)
	// 	&& aux->next->token.type != WORD)
	// 	return (0);
	return (1);
}
