/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:57:53 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/09 17:52:19 by cshingai         ###   ########.fr       */
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
