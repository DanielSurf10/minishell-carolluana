/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/07 19:25:58 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	aux_exec_builting(char *command, char *argv, t_minishell *shell)
{
	int	status_command;

	status_command = 0;
	printf("command: %s\n", command);
	if (ft_strcmp(command, "pwd") == 0)
		status_command = pwd();
	else if (ft_strcmp(command, "cd") == 0)
		change_directory(&shell->envp_list, argv);
	else if (ft_strcmp(command, "echo") == 0)
		status_command = echo(&argv);
	else if (ft_strcmp(command, "env") == 0)
		status_command = env(shell->envp_list);
	else if (ft_strcmp(command, "exit") == 0)
		status_command = ft_exit(shell, argv);
	else if (ft_strcmp(command, "export") == 0)
		status_command = export(argv, &shell->envp_list);
	else if (ft_strcmp(command, "unset") == 0)
		status_command = unset(argv, &shell->envp_list);
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


int	execute_builtin(t_minishell *shell)
{
	t_builtin	builtin;
	int	status;

	builtin.command = NULL;
	builtin.argv = NULL;
	builtin.status_builtin = 0;
	status = 0;
	if (shell->tree->tkn_type == 0)
	{
		if(is_builtin(shell->tree))
		{
			get_command(shell->tree->sub_list->token.lexeme, &builtin);
			status = aux_exec_builting(builtin.command, builtin.argv, shell);
		}
		else
			return (0);
	}
	free(builtin.argv);
	free(builtin.command);
	return (status);
}

void	get_command(char *content, t_builtin *builtin)
{
	char	*command_argument;
	int		len;

	command_argument = ft_strchr(content, ' ');
	printf("lexing: %s\n", content);
	if (command_argument != NULL)
	{
		len = ft_strlen(content) - ft_strlen(command_argument);
		builtin->command = malloc (sizeof (char) * (len + 1));
		if (!builtin->command)
			return ;
		builtin->command = ft_substr(content, 0, len);
		builtin->argv = ft_strdup(command_argument);
	}
	else
	{
		len = ft_strlen(content);
		builtin->command = ft_strdup(content);
	}
}
