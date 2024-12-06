/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:01:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/12/05 21:36:57 by lsouza-r         ###   ########.fr       */
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

	node = sub_list;
	while(node)
	{
		check_lexeme(node->token.lexeme, envp_list);
		node = node->next;
	}
}

void	check_lexeme(char *str, t_envp *envp_list)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	printf("oi\n");
	while(str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != '\0' && (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
		{
			i = expander_var(str, i, envp_list, &result);
			printf("%d\n", i);
		}
		else
			result = expander_word(str[i], result);
		i++;
	}
	printf("%s", result);
}

int	expander_var(char *str, int i, t_envp *envp_list, char **result)
{
	int		start;
	int		end;
	char	*var;
	char	*value;
	char	*temp;
	
	start = ++i;
	while ((ft_isalnum(str[i]) || str[i] == '_') && str[i] != '\0')
		i = i + 1;
	end = i - 1;
	var = ft_substr(str, start, end - start + 1);
	if (ft_check_key(var, envp_list) == 1)
		value = ft_strdup(ft_getenv(var, envp_list));
	free(var);
	temp = *result;
	*result = ft_strjoin(*result, value);
	free(temp);
	return (i - 1);
}

char	*expander_word(char c, char *result)
{
	char	*temp1;
	char	*temp2;
	
	if (result == NULL)
	{
		result = ft_calloc(2, sizeof (char));
		result[0] = c;
		result[1] = '\0';
	}
	else
	{
		temp1 = ft_calloc(2, sizeof (char));
		temp1[0] = c;
		temp1[1] = '\0';
		temp2 = result;
		result = ft_strjoin(result, temp1);
		free(temp1);
		free(temp2);
	}
	return (result);
}