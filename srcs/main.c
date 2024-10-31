/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/31 17:11:11 by cshingai         ###   ########.fr       */
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

// static void	print_tree(t_tree *tree)
// {
// 	if (tree)
// 	{
// 		printf("arvore: %s type: %d\n", tree->sub_list->token.lexeme, tree->sub_list->token.type);
// 		print_list(tree->sub_list);
// 		print_tree(tree->right);
// 		print_tree(tree->left);
// 	}
// }

int	main(int argc __attribute__((unused)), \
		char **argv __attribute__((unused)), char **envp)
{
	char	*prompt;
	t_minishell	shell;
	// extern char **environ;

	// pwd();
	// printf("chdir:%d\n", chdir("libs"));
	// pwd();
	while (1)
	{
		prompt = readline("minihell: ");
		if (prompt == NULL)
			break;
		shell.token_list = NULL;
		shell.tree = NULL;
		shell.token_list = tokenizer(prompt);
		shell.tree = build_root(shell.token_list);
		shell.envp_list = creat_env_list(envp);
		if (ft_strcmp(prompt, "exit") == 0)
		{
			free(prompt);
			shell.token_list = NULL;
			exit(1);
		}
		add_history(prompt);
		free_tree(&shell.tree);
		shell.token_list = NULL;
		pwd();
		change_directory(&shell.envp_list, "libs HOME");
		pwd();
	}
}
