/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:05:54 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/08 17:47:46 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*tokenizer(char *str)
{
	t_tkn_data	tkn_data;
	int			i;
	t_list		*token_list;

	token_list = NULL;
	init_token_data(&tkn_data, str);
	i = 0;
	while (i <= tkn_data.str_len)
	{
		tkn_data.state = token_get_next_state(tkn_data.state, str[i]);
		if (tkn_data.state != 1)
			tkn_data.lex_len++;
		else if (tkn_data.state == -1)
		{
			free_list(&token_list);
			break ;
		}
		if (is_final_state(tkn_data))
		{
			state_requires_backtrack(&tkn_data, &i);
			put_token_on_list(&tkn_data, str, &token_list, i);
		}
		i++;
	}
	return (token_list);
}

void	init_token_data(t_tkn_data *tkn_data, char *str)
{
	tkn_data->lex_len = 0;
	tkn_data->state = 1;
	tkn_data->str_len = ft_strlen(str);
}

int	is_final_state(t_tkn_data tkn_data)
{
	if (tkn_data.state == 20 || tkn_data.state == 31 || tkn_data.state == 32 ||
	 tkn_data.state == 41 || tkn_data.state == 42 || tkn_data.state == 53)
		return (1);
	return (0);
}

void	put_token_on_list(t_tkn_data *tkn_data, char *str, t_list **token_list, int i)
{
	tkn_data->tkn_type = get_token_type(tkn_data->state);
	if (tkn_data->tkn_type == WORD)
		tkn_data->lexema = ft_substr(str, i - (tkn_data->lex_len - 1), tkn_data->lex_len);
	else
		tkn_data->lexema = NULL;
	token_add_to_list(token_list, tkn_data->lexema, tkn_data->tkn_type);
	tkn_data->lex_len = 0;
	tkn_data->state = 1;
}