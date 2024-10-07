/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:05:54 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/07 20:24:06 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tokenizer(char *str, t_list *token_list)
{
	t_tkn_data	tkn_data;
	int			i;

	init_token_data(&tkn_data, str);
	printf("lex len:%d state: %d str_len: %d\n", tkn_data.lex_len, tkn_data.state, tkn_data.str_len);
	i = 0;
	while (i <= tkn_data.str_len)
	{
		tkn_data.state = token_get_next_state(tkn_data.state, str[i]);
		printf("current state: %d\n", tkn_data.state);
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
			printf("lex len: %d current i: %d\n", tkn_data.lex_len, i);
			put_token_on_list(tkn_data, str, token_list, i);
			tkn_data.lex_len = 0;
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
}

int	is_final_state(t_tkn_data tkn_data)
{
	if (tkn_data.state == 20 || tkn_data.state == 31 || tkn_data.state == 32 ||
	 tkn_data.state == 41 || tkn_data.state == 42 || tkn_data.state == 53)
		return (1);
	return (0);
}

void	put_token_on_list(t_tkn_data tkn_data, char *str, t_list *token_list, int i)
{
	tkn_data.tkn_type = get_token_type(tkn_data.state);
	printf("token type: %d\n", tkn_data.tkn_type);
	if (tkn_data.tkn_type == WORD)
		tkn_data.lexema = ft_substr(str, i - (tkn_data.lex_len - 1), tkn_data.lex_len);
	else
		tkn_data.lexema = NULL;
	printf("lexema: %s\n", tkn_data.lexema);
	token_add_to_list(&token_list, tkn_data.lexema, tkn_data.tkn_type);
}