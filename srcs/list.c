/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:28:09 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/27 20:09:44 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// uma modificação aleatória
// mais modificações

#include "../include/minishell.h"

//	My intention here is to pass the copy_prompt, with spaces between the
//	metachars, to a double linked list. So I can iterate between the chars
//	to identify the tolkens and latter the necessary adaptations.
//	obs.: tolkens are separeted by space or metacharacter
//	(' and "") aren't metacharacter

//utils
void	push_prompt_to_list(char **prompt)
{
	char			*copy_prompt;
	t_token_list	*list;
	int				idx;

	list = 0;
	idx = 0;
	copy_prompt = malloc(sizeof (char) * (3 * strlen(*prompt) + 1));
	strcpy_space(*prompt, copy_prompt);
	while (*copy_prompt)
	{
		printf("prompt: %c\n", copy_prompt[idx]);
		if (copy_prompt[idx] != ' ')
			create_node(&list, send_word(copy_prompt++));
		// idx++;
	}
	print_list(&list);
	// free(copy_prompt);
}

//	What is a tolken?
//	A tolken can be a word or a metacharacter
//	ex:
//	werf-> word, weu"jgh'-> word
//	> -> metachar, |-> metachar

// In create_list each node is a tolken
//utils
void	create_node(t_token_list **list, char *tolken)
{
	t_token_list	*node;
	t_token_list	*aux;

	node = malloc(sizeof (t_token_list));
	if (!node)
		return ;
	node->value = tolken;
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

// Just a checker if the list is working
// remover
void	print_list(t_token_list **list)
{
	t_token_list *aux;

	aux = *list;
	while (aux)
	{
		printf("list[%s]\n", aux->value);
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
			if (d > 0 && dest[d -1] != ' ' &&
				(dest[d -1] != '"' || dest[d-1] != '\''))
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

char *send_word(char *cpy_prompt)
{
	int		idx;
	char	*token;

	idx = 0;
	if (!token)
		return (NULL);
	while(cpy_prompt[idx] && cpy_prompt[idx] != ' ')
		idx++;
	token = malloc(sizeof (char) * (idx));
	token[idx] = '\0';
	return (token);
}
