/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:01:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/12/03 21:57:30 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


//func expander_coutes;
//func exapander_double_coutes;
//func expander_word;
//func expander_var;
void	expander(t_list *sub_list, t_envp *envp_list)
{
	t_list	*node;
	int		i;
	int		start;
	int		end;
	int		len_lexeme;
	int		
	char	*var;
	char	*value;

	node = sub_list;
	while(node)
	{
		i = 0;
		while(node->token->lexeme[i] != '\0')
		{
			if (node->token->lexeme[i] == '$' && (ft_isalpha(node->token->lexeme[i + 1])
				|| node->token->lexeme[i + 1] == '_'))
			{
				start = i++;
				while ((ft_isalnum(node->token->lexeme[i]) || node->token->lexeme[i] == '_') && node->token->lexeme[i] != '\0')
					i++;
				end = i - 1;
				var = ft_substr(node->token->lexeme, start, end - start + 1);
				if (ft_check_key(var, envp_list) == 1)
					//nova função
					value = ft_strdup(ft_getenv(var, envp_list));
				free(var);
			}
		}
	}
}