/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:07:56 by cshingai          #+#    #+#             */
/*   Updated: 2024/10/31 17:17:25 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exit(t_minishell *shell, char *arg)
{
    int	exit_status;
	
	exit_status = ft_atoi(arg);
    //codigo de saida
    //limpar t_list
    //limpar t_token_list
    //limpar t_tree
    //limpar t_env 
	return (exit_status);
}