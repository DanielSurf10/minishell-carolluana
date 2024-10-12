/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/12 14:05:51 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


/*
	In this first part of the main I have created the prompt. The prompt is
	created by the function readline. There are many functions, that still need
	to explore and probably will need to use, from the library of readline. But
	so far addhistory is the one who will bring history when press arrow up.
*/


// static void	print_list(t_list *list)
// {
// 	t_list *aux;

// 	aux = list;
// 	while (aux)
// 	{
// 		printf("lexema: %s type: %d\n", aux->token.lexeme, aux->token.type);
// 		aux = aux->next;
// 	}
// }

int	main(void)
{
	char	*prompt;
	t_minishell	base;

	while (1)
	{
		prompt = readline("minihell: ");
		if (prompt == NULL)
			break;
		base.token_list = NULL;
		base.tree = NULL;
		base.token_list = tokenizer(prompt);
		// push_prompt_to_list(&prompt);
		// print_list(base.token_list);
		base.tree = build_root(base.token_list);
		// if (last_pipe)
		// 	printf("\npos last pipe: %d\n", last_pipe->pos);
		if (strcmp(prompt, "exit") == 0)
		{
			free(prompt);
			free_list(&base.token_list);
			exit(1);
		}
		add_history(prompt);
		free_list(&base.token_list);
	}
}



