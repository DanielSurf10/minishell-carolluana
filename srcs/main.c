/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/19 20:28:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char	*line;
	int	i = 0;
	while (1)
	{
		line = readline("minihell: ");
		printf("prompt: %s\n", line);
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(1);
		}
		rl_on_new_line();
		i++;
	}
}
