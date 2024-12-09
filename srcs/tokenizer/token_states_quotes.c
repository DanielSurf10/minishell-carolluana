/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_states2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:41:29 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/09 17:42:26 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
