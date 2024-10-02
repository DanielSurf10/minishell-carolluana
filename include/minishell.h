/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:17:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/30 22:32:28 by lsouza-r         ###   ########.fr       */                                                     */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libs/libft/libft.h"

//****************************************************************************//
//                               TOKENIZER                                    //
//****************************************************************************//

enum e_token
{
	WORD,
	PIPE,
	REDIRECT_INPUT,
	REDIRECT_HEREDOC,
	REDIRECT_OUTPUT,
	REDIRECT_OUTPUT_APPEND,
	COMMAND
};

typedef struct s_token
{
	int		type;
	char	*lexame;
}	t_token;

typedef struct s_token_list
{
	t_token			token;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list ;

typedef struct s_tkn_data
{
	int		str_len;
	int		lex_len;
	char	*lexema;
	int		state;
	int		tkn_type;
	int		final_token;
}	t_tkn_data ;

typedef struct s_minishell
{
	struct s_list	*token_list;
}	t_minishell ;

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
int		ft_isspace(char c)


#endif
