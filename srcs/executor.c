/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:59:12 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/21 21:43:55 by lsouza-r         ###   ########.fr       */
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

void	exex_cmd(t_tree	*tree, t_minishell *shell, char side, int *fd)
{
	t_execve	*exec;
	int			i;
	char		*path_slash;
	char		*full_path;
	// int			pid;
	// int			status;
	
	if (side == 'L')
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
	else if (side == 'R')
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	i = 0;
	exec = ft_calloc(1, sizeof(t_execve));
	get_path(shell);
	// printf("get path ok\n");
	get_args(tree->sub_list, exec);
	// printf("get args ok\n");
	while (shell->path[i])
	{
		path_slash = ft_strjoin(shell->path[i], "/");
		full_path = ft_strjoin(path_slash, exec->cmd);
		free(path_slash);
		// printf("full path:%s\n", full_path);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			execve(full_path, exec->args, shell->envp);
			// else
			// 	waitpid(pid, &status, 0);
			break;
		}
		free(full_path);
		i++;
	}
}

void	executor(t_tree *tree, t_minishell *shell)
{
	if (tree->tkn_type == COMMAND)
		exex_cmd(tree, shell, NULL, NULL);
	if (tree->tkn_type == PIPE)
		handle_pipe(tree, shell);
}

int	handle_pipe(t_tree *tree, t_minishell *shell)
{
	int	fd[2];
	pid_t pid[2];

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	// printf("pipe ok\n");
	pid[0] = fork();
	if (pid[0] == 0)
		exex_cmd(tree->left, shell, 'L', fd);
	pid[1] = fork();
	if (pid[1] == 0)
		exex_cmd(tree->right, shell, 'R', fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
