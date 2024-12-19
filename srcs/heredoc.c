/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:21:54 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/12/18 18:40:06 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	hunt_heredoc(t_list *tkn_list)
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
			create_heredoc(current, tag);
			tag++;
		}
		current = current->next;
	}
}

void	create_heredoc(t_list *delimiter, int tag)
{
	char	*file_path;
	char	*curr;
	int		fd;
	// int		fd_stdin;
	char	*line;
	// nomes
	curr = ft_itoa(tag);
	file_path = ft_strjoin("/tmp/heredoc", curr);
	free(curr);
	//execute heredoc
	fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readline(">");
		if (ft_strcmp(line, delimiter->token.lexeme) != 0)
			ft_putstr_fd(line, fd);
		else
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	free(file_path);
}
