/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:01:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/12/06 18:48:54 by cshingai         ###   ########.fr       */
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
	char	*temp;

	node = sub_list;
	while(node)
	{
		temp = node->token.lexeme;
		node->token.lexeme = check_lexeme(node->token.lexeme, envp_list);
		free(temp);
		node = node->next;
	}
}

char	*check_lexeme(char *str, t_envp *envp_list)
{
	int		i;
	int		quotes;
	char	*result;

	i = 0;
	result = NULL;
	quotes = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != '\0' && (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
		{
			if (quotes == 0 || quotes == 1)
				i = expander_var(str, i, envp_list, &result);
			else
				expander_word(str[i], &result);
		}
		else if (str[i] == '\"' || str[i] == '\'')
			handle_quotes(str[i], &quotes, &result);
		else
			expander_word(str[i], &result);
		i++;
	}
	return (result);
}

int	expander_var(char *str, int i, t_envp *envp_list, char **result)
{
	int		start;
	int		end;
	char	*var;
	char	*value;
	char	*temp;

	start = ++i;
	if (*result == NULL)
	{
		*result = ft_calloc(1, sizeof (char));
		(*result)[0] = '\0';
	}
	while ((ft_isalnum(str[i]) || str[i] == '_') && str[i] != '\0')
		i = i + 1;
	end = i - 1;
	var = ft_substr(str, start, end - start + 1);
	if (ft_check_key(var, envp_list) == 1)
	{
		value = ft_strdup(ft_getenv(var, envp_list));
		temp = *result;
		*result = ft_strjoin(*result, value);
		free(temp);
	}
	free(var);
	return (i - 1);
}

void	expander_word(char c, char **result)
{
	char	*temp1;
	char	*temp2;

	if (*result == NULL)
	{
		*result = ft_calloc(2, sizeof (char));
		(*result)[0] = c;
		(*result)[1] = '\0';
	}
	else
	{
		temp1 = ft_calloc(2, sizeof (char));
		temp1[0] = c;
		temp1[1] = '\0';
		temp2 = *result;
		*result = ft_strjoin(*result, temp1);
		free(temp1);
		free(temp2);
	}
}

void	handle_quotes(char c, int *quotes, char **result)
{
	if (*quotes == 0)
	{
		if (c == '\"')
			(*quotes) = 1;
		else if (c == '\'')
			(*quotes) = 2;
	}
	else if ((*quotes == 1 && c == '\"') || (*quotes == 2 && c == '\''))
		(*quotes) = 0;
	else if ((*quotes == 1 && c == '\'') || (*quotes == 2 && c == '\"'))
		expander_word(c, result);
}
