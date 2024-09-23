/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/23 19:30:41 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char	*prompt;
	char	*cpy_prompt;

	cpy_prompt = malloc(sizeof (char) * (3 * strlen(prompt)));
	while (1)
	{
		prompt = readline("minihell: ");
		strcpy_space(prompt, cpy_prompt);
		printf("prompt: %s\n", cpy_prompt);
		// signal(SIGTERM, SIG_DFL);
		if (strcmp(prompt, "exit") == 0)
		{
			free(prompt);
			free(cpy_prompt);
			exit(1);
		}
		add_history(prompt);
	}
}

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
			if (dest[d -1] != ' ')
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
