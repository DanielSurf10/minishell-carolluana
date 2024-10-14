/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:44:30 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/10/14 18:16:36 by lsouza-r         ###   ########.fr       */
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

//****************************************************************************//
//                               TOKENIZER                                    //
//****************************************************************************//

typedef enum e_token
{
	WORD,
	PIPE,
	REDIRECT_INPUT,
	REDIRECT_HEREDOC,
	REDIRECT_OUTPUT,
	REDIRECT_OUTPUT_APPEND,
	COMMAND
}	t_token_enum;

typedef struct s_token
{
	int		type;
	char	*lexeme;
}	t_token;

typedef struct s_token_list
{
	int					pos;
	t_token				token;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}	t_list ;

typedef struct s_tkn_data
{
	int		str_len;
	int		lex_len;
	char	*lexema;
	int		state;
	int		tkn_type;
}	t_tkn_data ;

typedef struct s_tree
{
	int				tkn_type;
	t_list			*sub_list;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree ;

typedef struct s_minishell
{
	t_list	*token_list;
	t_tree	*tree;
}	t_minishell ;


// main.c

// lexing.c
// void	push_prompt_to_list(char **prompt);
// void	print_list(t_token_list **list);
// void	create_node(t_token_list **list, char *tolken);
// void	*strcpy_space(char *prompt, char *dest);
// char *send_word(char *cpy_prompt);
t_list	*tokenizer(char *str);
void	init_token_data(t_tkn_data *tkn_data, char *str);
int	is_final_state(t_tkn_data tkn_data);
void	put_token_on_list(t_tkn_data *tkn_data, char *str, t_list **token_list, int i);
int	get_token_type(int	state);
int	token_get_next_state(int state, char c);
int	token_get_state_30(char c);
int	token_get_state_40(char c);
void	state_requires_backtrack(t_tkn_data *tkn_data, int	*i);
int	token_get_state_1(char c);
int	ft_is_space(char c);
int	is_metachar(char c);
int	token_get_state_50(char c);
int	token_get_state_51(char c);
int	token_get_state_52(char c);

//utils.c
void	ft_strcpy(char *prompt, char *copy);
int		is_metachar(char c);
int		ft_isspace(char c);
void	token_add_to_list(t_list **token_list, char *lexeme, int token_type);
void	free_list(t_list **t_tree);

//parsing-tree
t_tree	*build_tree(t_list	*tkn_list);
t_list	*get_last_token(t_list	*tkn_list);
t_list	*hunt_last_pipe(t_list	*tkn_list);
t_tree	*build_root(t_list	*tkn_list);
void	build_branch(t_list *tkn_list, t_tree *pivot);
void	*free_tree(t_tree **tree);
t_list	*hunt_pipe_redir(t_list *tkn_list);
t_list	*hunt_redir(t_list	*tkn_list);

#endif