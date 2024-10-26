/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/26 17:40:41 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	exec_builting(char *command, char **argv, t_minishell shell)
{
	int	status_command;
	if (ft_strcmp(command, "pwd") == 0)
		status_command = pwd();
	else if (ft_strcmp(command, "env") == 0)
		status_command = env(shell.envp);
	else if (ft_strcmp(command, "export") == 0)
		status_command = export(*argv, shell.envp);
	else if (ft_strcmp(command, "unset") == 0)
		status_command = unset(*argv, shell.envp);
}
