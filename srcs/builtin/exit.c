/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:07:56 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/29 20:47:06 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_exit(t_minishell *shell, char **arg)
{
	int	exit_status;

	exit_status = 0;
	if (*arg)
	{
		if (!check_exit_arg(arg))
			return (1);
		exit_status = ft_atoi(*arg);
	}
	clear_args(shell->builtin.argv);
	free(shell->builtin.command);
	free_tree(&shell->tree);
	free_env_list(shell->envp_list);
	free_envp_str(shell->envp);
	rl_clear_history();
	free(shell->prompt);
	exit(exit_status);
}

int	check_exit_arg(char **arg)
{
	int	idx1;

	idx1 = 0;
	while (arg[idx1])
		idx1++;
	if (idx1 > 1)
	{
		ft_putstr_fd("minihell: exit: too many arguments\n", STDERR_FILENO);
		return (0);
	}
	idx1 = 0;
	while (*arg)
	{
		if (ft_isalpha(*arg[idx1]))
		{
			printf("minihell: exit: %s: numeric argument required\n", *arg);
			return (0);
		}
		idx1++;
	}
	return (1);
}
