/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:30:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/15 16:36:45 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstadd_back_gnl(t_list_gnl **lst, char c)
{
	t_list_gnl	*new;
	t_list_gnl	*aux;

	new = malloc(sizeof(t_list_gnl));
	if (!new)
		return (FAIL);
	new->content = c;
	new->next = NULL;
	if (!(*lst))
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (0);
}

void	ft_lstclear_gnl(t_list_gnl **lst)
{
	t_list_gnl	*aux1;
	t_list_gnl	*aux2;

	if (lst)
	{
		aux1 = *lst;
		while (aux1)
		{
			aux2 = aux1->next;
			free(aux1);
			aux1 = aux2;
		}
		*lst = NULL;
	}
}

char	*read_fd(int fd, t_list_gnl **line)
{
	int		read_status;
	char	*line_part;
	char	*line_to_return;

	read_status = READ;
	line_part = NULL;
	line_to_return = NULL;
	if (!line)
		return (NULL);
	while (read_status == READ)
	{
		line_part = (char *) malloc(BUFFER_SIZE * sizeof(char));
		if (!line_part)
			return (NULL);
		read_status = read(fd, line_part, BUFFER_SIZE);
		if (read_status != FAIL)
			read_status = put_in_list(line, line_part, read_status);
		free(line_part);
		line_part = NULL;
	}
	if (read_status == FAIL)
		return (NULL);
	if (read_status == BUILD_STRING)
		line_to_return = build_line(line);
	return (line_to_return);
}

char	*get_next_line(int fd)
{
	char			*line_to_return;
	static t_list_gnl	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_to_return = read_fd(fd, &line);
	if (!line_to_return)
		ft_lstclear_gnl(&line);
	return (line_to_return);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:01 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/15 16:45:10 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lst_next_line_size(t_list_gnl *lst)
{
	int		i;
	t_list_gnl	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		i++;
		if (aux->content == '\n')
			return (i);
		aux = aux->next;
	}
	return (i);
}

// int	need_to_read(t_list_gnl *line)
// {
// 	int	i;
//
// 	i = 0;
// 	while (line)
// 	{
// 		i++;
// 		if (line->content == '\n')
// 			return (BUILD_STRING);
// 		line = line->next;
// 	}
// 	return (READ);
// }

char	*build_line(t_list_gnl **line)
{
	int		i;
	int		line_size;
	char	*line_to_return;
	t_list_gnl	*aux;

	i = 0;
	if (*line == NULL)
		return (NULL);
	line_size = ft_lst_next_line_size(*line);
	line_to_return = (char *) malloc(line_size + 1);
	if (!line_to_return)
		return (NULL);
	line_to_return[line_size] = '\0';
	while (i < line_size)
	{
		aux = *line;
		line_to_return[i] = (*line)->content;
		*line = (*line)->next;
		free(aux);
		i++;
	}
	aux = NULL;
	return (line_to_return);
}

int	put_in_list(t_list_gnl **line, char *line_part, int size_readed)
{
	int	i;
	int	status_node_creation;
	int	return_status;

	i = 0;
	return_status = READ;
	if (!line_part)
		return (FAIL);
	if (size_readed == 0)
		return (BUILD_STRING);
	while (i < size_readed)
	{
		status_node_creation = ft_lstadd_back_gnl(line, line_part[i]);
		if (status_node_creation == FAIL)
			return (FAIL);
		if (line_part[i] == '\n')
			return_status = BUILD_STRING;
		i++;
	}
	return (return_status);
}
