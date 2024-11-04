/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/04 17:32:44 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	exec_builting(char *command, char **argv, t_minishell *shell)
{
	int	status_command;
	if (ft_strcmp(command, "pwd") == 0)
		status_command = pwd();
	else if (ft_strcmp(command, "cd") == 0)
		change_directory(shell->envp_list, *argv);
	else if (ft_strcmp(command, "env") == 0)
		status_command = echo(argv);
	else if (ft_strcmp(command, "env") == 0)
		status_command = env(shell->envp_list);
	else if (ft_strcmp(command, "exit") == 0)
		status_command = ft_exit(shell, *argv);
	else if (ft_strcmp(command, "export") == 0)
		status_command = export(*argv, shell->envp_list);
	else if (ft_strcmp(command, "unset") == 0)
		status_command = unset(*argv, shell->envp_list);
}
