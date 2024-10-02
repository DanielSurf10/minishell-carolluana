/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:05:54 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/09/30 22:32:57 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tokenizer(char *str, t_list *token_list)
{
	t_tkn_data	tkn_data;
	int			i;

	init_token_data(&tkn_data, str);
	i = 0;
	while (i < tkn_data.str_len)
	{
		tkn_data.state = get_tkn_state(tkn_data.state, str[i]);
		if (tkn_data.state == 1)
			tkn_data.lex_len++;
		else if (tkn_data.state == -1)
		{
			free_list(token_list);
			break ;
		}
		if (is_final_state(tkn_data))
		{
			put_token_in_list(tkn_data, str, token_list);
			tkn_data.state = 1;
		}
		i++;
	}
}

void	init_token_data(t_tkn_data *tkn_data, char *str)
{
	tkn_data->lex_len = 0;
	tkn_data->state = 1;
	tkn_data->str_len = ft_strlen(str);
	tkn_data->final_token = 0;
}

int	is_final_state(t_tkn_data tkn_data)
{
	if (tkn_data.state == 20)
	
	
	 || state == 31 || state == 32 || state == 42 || state == 42 || state == 53)
		return (1);
	return (0);
}

void	put_token_in_list(t_tkn_data tkn_data, char *str, t_list *token_list)
{
	
}