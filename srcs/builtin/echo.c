/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:32:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/24 19:00:53 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	echo(char **arg)
{
	// int	i;
	int	has_flag;

	// i = 0;
	has_flag = 0;
	if (ft_strcmp(arg[1], "n") == 0)
	{
		has_flag = 1;
		arg++;
	}
	if (has_flag == 1)
		ft_putendl_fd(*arg, STDOUT_FILENO);
	else
		ft_putstr_fd(*arg, STDOUT_FILENO);
	return (0);
}
