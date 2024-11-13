/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:07:56 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/12 21:30:47 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_exit(t_minishell *shell, char *arg)
{
	int	exit_status;

	exit_status = 0;
	if (arg)
	{
		if (!check_exit_arg(arg))
			return (1);
		exit_status = ft_atoi(arg);
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

int	check_exit_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
		{
			printf("minihell: exit: %s: numeric argument required\n", arg);
			return (0);
		}
		if (arg[i] && ft_is_space(arg[i + 1]) && arg[i + 2] != '\0')
		{
			printf("minihell: exit: too many arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}
