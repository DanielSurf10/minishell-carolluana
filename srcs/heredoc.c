/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:21:54 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/12/24 18:09:15 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	hunt_heredoc(t_list *tkn_list, t_minishell *shell)
{
	t_list	*current;
	int		tag;

	tag = 0;
	current = tkn_list;
	while (current)
	{
		if (current->token.type == REDIRECT_HEREDOC)
		{
			current = current->next;
			create_heredoc(current, tag, shell);
			tag++;
		}
		current = current->next;
	}
}

void	create_heredoc(t_list *delimiter, int tag, t_minishell *shell)
{
	char	*file_path;
	char	*curr;
	int		fd;
	char	*line;

	curr = ft_itoa(tag);
	file_path = ft_strjoin("/tmp/heredoc", curr);
	free(curr);
	fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		signals_for_heredoc();
		line = readline("> ");
		if (line == NULL)
			break;
		if (ft_strcmp(line, delimiter->token.lexeme) != 0)
		{
			expander_heredoc(&line, shell);
			ft_putendl_fd(line, fd);
		}
		else
		{
			free(delimiter->token.lexeme);
			delimiter->token.lexeme = ft_strdup(file_path);
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	free(file_path);
}
