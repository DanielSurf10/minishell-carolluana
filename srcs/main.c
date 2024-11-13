/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:25 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/13 17:58:50 by cshingai         ###   ########.fr       */
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
	// char	*prompt;
	t_minishell	shell;

	init_shell(&shell);
	shell.envp_list = create_env_list(envp);
	shell.envp = list_to_str(shell.envp_list);
	while (1)
	{
		shell.prompt = readline("minihell: ");
		if (shell.prompt == NULL)
			break ;
		shell.token_list = tokenizer(shell.prompt);
		shell.tree = build_root(shell.token_list);

		//teste
		execute_builtin(&shell);
		// export("PWD=oi", &shell.envp_list);
		// env(shell.envp_list);

		add_history(shell.prompt);
		free_tree(&shell.tree);
		shell.token_list = NULL;
	}
	rl_clear_history();
	free_env_list(shell.envp_list);
	free_envp_str(shell.envp);
}
