/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:17:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/25 20:05:14 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libs/libft/libft.h"

typedef struct s_token
{
	int		type;
	char	*lexame;
}	t_token;

typedef struct s_list
{
	char	value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list ;

// main.c
int		is_metachar(char c);

// lexing.c
void	push_prompt_to_list(char **prompt);
void	print_list(t_list **list);
void	create_list(t_list **list, char c);
void	*strcpy_space(char *prompt, char *dest);


#endif
