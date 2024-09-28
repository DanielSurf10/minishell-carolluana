/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:08 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/28 18:46:01 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_metachar(char c)
{
	// if (c == '"')
	// 	return (2);
	// else if (c == '\'')
	// 	return (1);
	// ft_strchr("|<>", c);
	if (c == '|')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else
		return (0);
}

void	ft_strcpy(char *prompt, char *copy)
{
	int	i;

	i = 0;
	while(prompt[i])
	{
		copy[i] = prompt[i];
		i++;
	}
}
