/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:08 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/19 18:47:19 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_free_split(char **split)
{
	int	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

void	init_shell(t_minishell *shell)
{
	shell->token_list = NULL;
	shell->tree = NULL;
	shell->envp_list = NULL;
	shell->envp = NULL;
	shell->status = 0;
	g_signal = 0;
	shell->fd_stdin = dup(STDIN_FILENO);
	shell->fd_stdout = dup(STDOUT_FILENO);
}
