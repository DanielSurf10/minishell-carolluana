/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:07:56 by cshingai          #+#    #+#             */
/*   Updated: 2024/11/04 17:44:55 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_exit(t_minishell *shell, char *arg)
{
	int	exit_status;

//verificar se é num
	exit_status = ft_atoi(arg);
	free_tree(&shell->tree);
	free_env_list(shell->envp_list);
	free_envp_str(shell->envp);
	rl_clear_history();
	free(shell->prompt);
	exit(exit_status);
}
