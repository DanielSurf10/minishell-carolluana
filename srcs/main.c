/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/20 20:05:31 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char	*prompt;
	char	*cpy_prompt;
	char	*dest;

	dest = malloc(sizeof (char) * (2 * strlen(prompt)));
	while (1)
	{
		prompt = readline("minihell: ");
		printf("prompt: %s\n", prompt);
		if (strcmp(prompt, "exit") == 0)
		{
			free(prompt);
			exit(1);
		}
		add_history(prompt);
	}
}

int	is_metachar(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '"')
			return (1);
		else if (prompt[i] == "'")
			return (1);
		else if (prompt[i] == '|')
			return(1);
		i++;
	}
}

// char	*strcpy_space(char *prompt, char *dest)
// {
// 	int	i;

// 	i = 0;
// 	while(prompt[i])
// 	{
// 		dest[i] = prompt[i];
// 		i++;
// 	}
// }
