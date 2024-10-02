/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:57:53 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/30 21:05:55 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	token_get_state_nbr(char c)
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
	else if (c == '"')
		state = 52;
	else if (!is_metachar(c))
		state = 50;
	else
		state = -1;
	return (state);
}


// the pipe (state 20) doesn't change it's state
int	token_get_next_state(int state, char c)
{
	int	next_state;

	if (state == 1)
		next_state = 1;
	else if (next_state == 30)
		next_state = token_get_state_30(c);
	else if (next_state == 40)
		next_state = token_get_state_40(c);
	else if (next_state == 50)
		next_state = token_get_state_50(c);
	else if (next_state == 51)
		next_state = token_get_state_51(c);
	else if (next_state == 52)
		next_state = token_get_state_52(c);
}

int	token_get_state_30(char c)
{
	int	state;

	if (c == '>')
		state = 31;
	else if (c != '>')
		state = 32;
	return (state);
}

int	token_get_state_40(char c)
{
	int	state;

	if (c == '<')
		state = 41;
	else if (c != '<')
		state = 42;
	return (state);
}

int	state_requires_backtrack(int state)
{
	if (state == 32 || state == 42)
		return (1);
	else
		return (0);
}
