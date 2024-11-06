/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/05 18:01:39 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	aux_exec_builting(char *command, char **argv, t_minishell *shell)
{
	int	status_command;

	status_command = 0;
	if (ft_strcmp(command, "pwd") == 0)
		status_command = pwd();
	else if (ft_strcmp(command, "cd") == 0)
		change_directory(&shell->envp_list, *argv);
	else if (ft_strcmp(command, "echo") == 0)
		status_command = echo(argv);
	else if (ft_strcmp(command, "env") == 0)
		status_command = env(shell->envp_list);
	else if (ft_strcmp(command, "exit") == 0)
		status_command = ft_exit(shell, *argv);
	else if (ft_strcmp(command, "export") == 0)
		status_command = export(*argv, &shell->envp_list);
	else if (ft_strcmp(command, "unset") == 0)
		status_command = unset(*argv, &shell->envp_list);
	return (status_command);
}

int	is_builtin(t_tree *tree)
{
	if (ft_strcmp(tree->sub_list->token.lexeme, "pwd")
		|| ft_strcmp(tree->sub_list->token.lexeme, "cd")
		|| ft_strcmp(tree->sub_list->token.lexeme, "echo")
		|| ft_strcmp(tree->sub_list->token.lexeme, "env")
		|| ft_strcmp(tree->sub_list->token.lexeme, "exit")
		|| ft_strcmp(tree->sub_list->token.lexeme, "export")
		|| ft_strcmp(tree->sub_list->token.lexeme, "unset"))
		return (1);
	else
		return (0);
}


int	execute_builtin(t_tree *tree)
{
	// char	*space;
	// char	**command;
	int	status;

	status = 0;
	if (tree->tkn_type == 0)
	{
		status = is_builtin(tree);
		// space = ft_strchr(tree->sub_list->token.lexeme, ' ');
		// strchr()
	}
	return (status);
}

void	init_builtin(t_builtin *builtin)
{
	builtin->argv = NULL;
	builtin->command = NULL;
	builtin->status_builtin = 0;
}
