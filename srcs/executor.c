/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:59:12 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/18 21:43:07 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_path(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	shell->path = ft_split(shell->envp[i] + 5, ':');
}
void	get_args(t_list *sub_list, t_execve *exec)
{
	t_list	*node;
	int		i;
	char	**args;

	i = 0;
	node = sub_list;
	if (!sub_list)
		return ;
	exec->cmd = ft_strdup(node->token.lexeme);
	while (node)
	{
		i++;
		node = node->next;
	}
	args = ft_calloc(i + 1, sizeof (char *));
	i = 0;
	node = sub_list;
	while (node)
	{
		args[i] = ft_strdup(node->token.lexeme);
		i++;
		node = node->next;
	}
	exec->args = args;
}

void	executor(t_tree	*tree, t_minishell *shell)
{
	t_execve	*exec;
	int			i;
	char		*path_slash;
	char		*full_path;
	int			pid;
	int			status;
	
	i = 0;
	exec = ft_calloc(1, sizeof(t_execve));
	get_path(shell);
	get_args(tree->sub_list, exec);
	while (shell->path[i])
	{
		path_slash = ft_strjoin(shell->path[i], "/");
		full_path = ft_strjoin(path_slash, exec->cmd);
		free(path_slash);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				status = execve(full_path, exec->args, shell->envp);
			else
				waitpid(pid, &status, 0);
		}
		free(full_path);
		i++;
	}
}