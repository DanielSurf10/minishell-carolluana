/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:59:12 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/12/28 16:41:05 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * get_path - Retrieves the PATH environment variable and splits it into an array.
 * @shell: Pointer to the minishell structure containing environment variables.
 */
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
/**
 * get_args - Extracts command arguments from a linked list and stores them in exec structure.
 * @sub_list: Pointer to the linked list containing command tokens.
 * @exec: Pointer to the execve structure to store command and arguments.
 */
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
	args[i] = NULL;
	exec->args = args;
}
/**
 * exec_cmd - Executes a command by searching for it in the PATH and using execve.
 * @tree: Pointer to the syntax tree node containing the command.
 * @shell: Pointer to the minishell structure containing environment variables.
 */
void	exec_cmd(t_tree	*tree, t_minishell *shell)
{
	int			ret_code;
	t_execve	*exec;
	int			i;
	char		*path_slash;
	char		*full_path;

	i = 0;
	ret_code = 0;
	exec = ft_calloc(1, sizeof(t_execve));
	get_path(shell);
	get_args(tree->sub_list, exec);
	if (ft_strchr(exec->cmd, '/') == NULL && exec->cmd[0])
	{
		while (shell->path[i])
		{
			path_slash = ft_strjoin(shell->path[i], "/");
			full_path = ft_strjoin(path_slash, exec->cmd);
			free(path_slash);
			if (access(full_path, F_OK | X_OK) == 0)
				break;
			free(full_path);
			full_path = NULL;
			i++;
		}
	}
	else
		full_path = ft_strdup(exec->cmd);
	if (ft_strchr(exec->cmd, '/') != NULL || full_path)
		execve(full_path, exec->args, shell->envp);
	if (!full_path || !full_path[0] || access(full_path, F_OK) != 0)
	{
		printf("oi1\n");
		perror(exec->cmd);
		ret_code = 127;
	}
	else if (full_path && access(full_path, F_OK | X_OK) != 0)
	{
		printf("oi2\n");
		perror(full_path);
		ret_code = 126;
	}
	else
	{
		printf("oi3\n");
		perror(full_path);
		ret_code = 1;
	}
	// free(full_path);
	ft_free_split(shell->path);
	ft_free_split(exec->args);
	free(exec->cmd);
	free(exec);
	shell->status = ret_code;
	exit(ret_code);
}
/**
 * executor - Executes commands or pipelines based on the syntax tree.
 * @tree: Pointer to the syntax tree node.
 * @shell: Pointer to the minishell structure containing environment variables.
 */
void	executor(t_tree *tree, t_minishell *shell)
{
	signals_for_command();
	if (tree->tkn_type == COMMAND && tree->sub_list)
		exec_single_cmd(tree, shell);
	else if (tree->tkn_type == PIPE && tree->left->tkn_type == PIPE)
	{
		tree->left->parent = tree;
		pipe(tree->fd);
		ft_lstadd_back(&(shell->fd_list), ft_lstnew((void *)((long)tree->fd[0])));
		ft_lstadd_back(&(shell->fd_list), ft_lstnew((void *)((long)tree->fd[1])));
		executor(tree->left, shell);
		handle_pipe(tree, shell, 0);
		close(tree->fd[0]);
		close(tree->fd[1]);
	}
	else if (tree->tkn_type == PIPE && tree->left->tkn_type == COMMAND)
	{
		pipe(tree->fd);
		ft_lstadd_back(&(shell->fd_list), ft_lstnew((void *)((long)tree->fd[0])));
		ft_lstadd_back(&(shell->fd_list), ft_lstnew((void *)((long)tree->fd[1])));
		handle_pipe(tree, shell, 1);
		close(tree->fd[0]);
		close(tree->fd[1]);
	}
}

/**
 * handle_pipe - Handles the execution of commands connected by pipes.
 * @tree: Pointer to the syntax tree node.
 * @shell: Pointer to the minishell structure containing environment variables.
 * @left: Integer indicating if the left command should be executed first.
 *
 * Return: Always returns 0.
 */
int	handle_pipe(t_tree *tree, t_minishell *shell, int left)
{
	pid_t pid[2];

	if (left == 1)
	{
		pid[0] = fork();
		if (pid[0] == 0)
		{
			dup2(tree->fd[1], STDOUT_FILENO);
			close(tree->fd[0]);
			close(tree->fd[1]);
			if (handle_redir(tree->left, shell) == 0)
			{
				expander(tree->left->sub_list, shell);
				close_fd(shell);
				if (is_builtin(tree->left))
				{
					shell->status = execute_builtin(shell, tree->left);
					exit(shell->status);
				}
				exec_cmd(tree->left, shell);
			}
			exit(1);
		}
		ft_lstadd_back(&(shell->pid), ft_lstnew((void *)((long)pid[0])));
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		dup2(tree->fd[0], STDIN_FILENO);
		if (tree->parent)
		{
			dup2(tree->parent->fd[1], STDOUT_FILENO);
			close(tree->parent->fd[1]);
			// close(tree->parent->fd[0]);
		}
		close(tree->fd[0]);
		close(tree->fd[1]);
		if (handle_redir(tree->right, shell) == 0)
		{
			expander(tree->right->sub_list, shell);
			close_fd(shell);
			if (is_builtin(tree->right))
			{
				shell->status = execute_builtin(shell, tree->right);
				exit(shell->status);
			}
			exec_cmd(tree->right, shell);
		}
		exit(1);
	}
	ft_lstadd_back(&(shell->pid), ft_lstnew((void *)((long)pid[1])));
		// waitpid(pid[0], &shell->status, 0);

	// waitpid(pid[1], &shell->status, 0);
	// shell->status = WEXITSTATUS(shell->status);
	return (0);
}

/**
 * handle_redir - Handles input and output redirections for a command.
 * @tree: Pointer to the syntax tree node containing redirection information.
 */
int	handle_redir(t_tree	*tree, t_minishell *shell)
{
	t_redir	*node;
	int		fd;
	char	*expanded_file;

	node = tree->redir;
	expanded_file = NULL;
	while (node)
	{
		expanded_file = check_lexeme(node->file, shell);
		if (node->rd_type == REDIRECT_OUTPUT)
		{
			fd = open(expanded_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (fd == -1)
			{
				perror(expanded_file);
				return (1);
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (node->rd_type == REDIRECT_OUTPUT_APPEND)
		{
			fd = open(expanded_file, O_CREAT | O_WRONLY | O_APPEND, 0644);
			if (fd == -1)
			{
				perror(expanded_file);
				return (1);
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (node->rd_type == REDIRECT_INPUT)
		{
			fd = open(expanded_file, O_RDONLY);
			if (fd == -1)
			{
				perror(expanded_file);
				return (1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else if (node->rd_type == REDIRECT_HEREDOC)
		{
			fd = open(expanded_file, O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		free(expanded_file);
		expanded_file = NULL;
		node = node->next;
	}
	free(expanded_file);
	expanded_file = NULL;
	return (0);
}
/**
 * exec_single_cmd - Executes a single command, handling redirections and built-ins.
 * @tree: Pointer to the syntax tree node containing the command.
 * @shell: Pointer to the minishell structure containing environment variables.
 */
void	exec_single_cmd(t_tree *tree, t_minishell *shell)
{
	int	pid;

	if (is_builtin(tree) == 1)
	{
		if (handle_redir(tree, shell) == 0)
		{
			expander(tree->sub_list, shell);
			shell->status = execute_builtin(shell, tree);
		}
		else
			shell->status = 1;
		return ;
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (handle_redir(tree, shell) == 0)
			{
				expander(tree->sub_list, shell);
				close_fd(shell);
				exec_cmd(tree, shell);
			}
			exit(1);
		}
		waitpid(pid, &shell->status, 0);
		shell->status = WEXITSTATUS(shell->status);
	}
}

void	wait_pid(t_minishell *shell)
{
	t_lst	*curr;

	curr = shell->pid;
	while (curr)
	{
		waitpid((pid_t)((long)(curr->content)), &shell->status, 0);
		shell->status = WEXITSTATUS(shell->status);
		curr = curr->next;
	}
}

void	close_fd(t_minishell *shell)
{
	t_lst	*curr;

	curr = shell->fd_list;
	while (curr)
	{
		close((long)curr->content);
		curr = curr->next;
	}
}
