/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:28:09 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/26 17:01:06 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// uma modificação aleatória


#include "../include/minishell.h"

/*
	My intention here is to pass the copy_prompt, with spaces between the
	metachars, to a double linked list. So I can iterate between the chars
	to identify the tolkens and latter the necessary adaptations.
*/
//utils
void	push_prompt_to_list(char **prompt)
{
	char	*cpy_prompt;
	t_list	*list;
	int		idx;

	list = 0;
	idx = 0;
	cpy_prompt = malloc(sizeof (char) * (3 * strlen(*prompt) + 1));
	strcpy_space(*prompt, cpy_prompt);
	printf("prompt: %s\n", cpy_prompt);
	while (cpy_prompt[idx])
		create_list(&list, cpy_prompt[idx++]);
	print_list(&list);
	free(cpy_prompt);
}
//utils
void	create_list(t_list **list, char c)
{
	t_list	*node;
	t_list	*aux;

	node = malloc(sizeof (t_list));
	if (!node)
		return ;
	node->value = c;
	node->next = NULL;
	if (*list == NULL)
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		aux = *list;
		while(aux->next)
			aux = aux->next;
		aux->next = node;
		node->prev = aux;
	}
}

// Just a checker is the list is working
// remover
void	print_list(t_list **list)
{
	t_list *aux;

	aux = *list;
	while (aux)
	{
		printf("list[%c]\n", aux->value);
		aux = aux->next;
	}
}

// copy prompt with spaces between metachars
// utils
void	*strcpy_space(char *prompt, char *dest)
{
	int	p;
	int	d;

	p = 0;
	d = 0;
	while(prompt[p])
	{
		if (is_metachar(prompt[p]))
		{
			if ( d > 0 && dest[d -1] != ' ')
				dest[d++] = ' ';
			dest[d++] = prompt[p++];
			dest[d++] = ' ';
		}
		else
			dest[d++] = prompt[p++];
	}
	dest[d] = '\0';
	return (NULL);
}
