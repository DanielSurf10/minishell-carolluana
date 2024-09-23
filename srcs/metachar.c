/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metachar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:08 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/23 18:24:19 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_metachar(char c)
{
	if (c == '"')
		return (2);
	else if (c == '\'')
		return (2);
	else if (c == '|')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else
		return (0);
}

// int	sep_signals(char c)
// {
// 	if ()
// }
