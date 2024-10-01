/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:05:54 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/09/30 21:47:50 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tokenizer(char *str, t_list token_list)
{
	t_tkn_data	tkn_data;
	int			i;

	init_token_data(&tkn_data, str);
	i = 0;
	while (i < tkn_data.lex_len)
	{
		tkn_data.state = 
	}
	
}

void	init_token_data(t_tkn_data *tkn_data, char *str)
{
	tkn_data->lex_len = ft_strlen(str);
	tkn_data->state = 1;
}