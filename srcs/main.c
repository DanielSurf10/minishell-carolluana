/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/02 18:02:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	In this first part of the main I have created the prompt. The prompt is
	created by the function readline. There are many functions, that still need
	to explore and probably will need to use, from the library of readline. But
	so far addhistory is the one who will bring history when press arrow up.
*/
int	main(void)
{
	char	*prompt;
	t_minishell	base;

	base.token_list = NULL;
	while (1)
	{
		prompt = readline("minihell: ");
		tokenizer(prompt, base.token_list);
		push_prompt_to_list(&prompt);
		if (strcmp(prompt, "exit") == 0)
		{
			free(prompt);
			exit(1);
		}
		add_history(prompt);
	}
}
