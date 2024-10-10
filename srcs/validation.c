/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:09:36 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/10 20:56:29 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	valid_list(t_list *list)
{
	int pipe_valid;
	int redirect_valid;

	pipe_valid = valid_pipe(list);
	redirect_valid = valid_redirect(list);
	return(pipe_valid * redirect_valid);
}

int	valid_pipe(t_list *list)
{
	t_list	*aux;

	aux = list;
	while (aux)
	{
		if ((aux->token.type == 1 && aux->next == NULL)
			|| (aux->token.type == 1 && aux->prev == NULL))
		{
				return (0);
		}
		else if (aux->token.type == 1 && aux->next->token.type == 1)
		{
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
		if ((aux->token.type >= 2 && aux->token.type <= 5)
			&& (aux->next == NULL))
			return (0);
		else if (aux->token.type == 5
			&& (aux->next->token.type == 4 || aux->next->token.type == 5))
			return (0);
		else if (aux->token.type == 3
			&& (aux->next->token.type == 2 || aux->next->token.type == 3))
			return (0);
		else if ((aux->token.type == 2 && aux->next->token.type == 4)
			||	(aux->token.type == 2 && aux->next->token.type == 4))
			return (0);
		aux = aux->next;
	}
	return (1);
}
