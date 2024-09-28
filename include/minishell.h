/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:17:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/27 19:51:35 by cshingai         ###   ########.fr       */
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

typedef struct s_token_list
{
	char	*value;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}	t_token_list ;

// main.c

// lexing.c
void	push_prompt_to_list(char **prompt);
void	print_list(t_token_list **list);
void	create_node(t_token_list **list, char *tolken);
void	*strcpy_space(char *prompt, char *dest);
char *send_word(char *cpy_prompt);

//utils.c
void	ft_strcpy(char *prompt, char *copy);
int		is_metachar(char c);


#endif
