/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:57:53 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/08 17:23:11 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_token_type(int	state)
{
	if (state == 20)
		return (PIPE);
	else if (state == 31)
		return (REDIRECT_OUTPUT_APPEND);
	else if (state == 32)
		return (REDIRECT_OUTPUT);
	else if (state == 41)
		return (REDIRECT_HEREDOC);
	else if (state == 42)
		return (REDIRECT_INPUT);
	else if (state == 53)
		return (WORD);
	else
		return (-1);
}
// the pipe (state 20) doesn't change it's state
int	token_get_next_state(int state, char c)
{
	int	next_state;

	if (state == 1)
		next_state = token_get_state_1(c);
	else if (state == 30)
		next_state = token_get_state_30(c);
	else if (state == 40)
		next_state = token_get_state_40(c);
	else if (state == 50)
		next_state = token_get_state_50(c);
	else if (state == 51)
		next_state = token_get_state_51(c);
	else if (state == 52)
		next_state = token_get_state_52(c);
	else
		next_state = -1;
	return (next_state);
}

int	token_get_state_30(char c)
{
	int	state;

	if (c == '>')
		state = 31;
	else if (c != '>')
		state = 32;
	else
		state = -1;
	return (state);
}

int	token_get_state_40(char c)
{
	int	state;

	if (c == '<')
		state = 41;
	else if (c != '<')
		state = 42;
	else
		state = -1;
	return (state);
}

void	state_requires_backtrack(t_tkn_data *tkn_data, int	*i)
{
	if (tkn_data->state == 32 || tkn_data->state == 42 || tkn_data->state == 53)
	{
		tkn_data->lex_len = tkn_data->lex_len - 1;
		*i = (*i) - 1;
	}
}
int	token_get_state_1(char c)
{
	int	state;

	if (c == '|')
		state = 20;
	else if (c == '>')
		state = 30;
	else if (c == '<')
		state = 40;
	else if (c == '\'')
		state = 51;
	else if (c == '\"')
		state = 52;
	else if (ft_is_space(c) || c == '\0')
		state = 1;
	else if (!is_metachar(c))
		state = 50;
	else
		state = -1;
	return (state);
}

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

int	token_get_state_50(char c)
{
	int	state;
	
	if (c == '\'')
		state = 51;
	else if (c == '\"')
		state = 52;
	else if (is_metachar(c) || c == '\0' || ft_is_space(c))
		state = 53;
	else if (!is_metachar(c))
		state = 50;
	else
		state = -1;
	return (state);
}

int	token_get_state_51(char c)
{
	int	state;

	if (c == '\0')
		state = -1;
	else if (c == '\'')
		state = 50;
	else if (c != '\'')
		state = 51;
	else
		state = -1;
	return (state);
}

int	token_get_state_52(char c)
{
	int	state;

	if (c == '\0')
		state = -1;
	else if (c == '\"')
		state = 50;
	else if (c != '\"')
		state = 52;
	else
		state = -1;
	return (state);
}

