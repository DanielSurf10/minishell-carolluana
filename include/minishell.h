/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:44:30 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/11/20 20:09:24 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PATH_MAX 4096

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libs/libft/libft.h"
# include "./parsing.h"


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

/*
* @brief s_token
*
*/
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

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_builtin
{
	char	**argv;
	char	*command;
	int		status_builtin;
}	t_builtin;

typedef struct s_minishell
{
	t_list	*token_list;
	t_tree	*tree;
	t_envp	*envp_list;
	t_builtin	builtin;
	char	**envp;
	char	**path;
	char	*prompt;
	int		status;
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
int		is_final_state(t_tkn_data tkn_data);
void	put_token_on_list(t_tkn_data *tkn_data, char *str, t_list **token_list, int i);
int		get_token_type(int	state);
int		token_get_next_state(int state, char c);
int		token_get_state_30(char c);
int		token_get_state_40(char c);
void	state_requires_backtrack(t_tkn_data *tkn_data, int	*i);
int		token_get_state_1(char c);
int		ft_is_space(char c);
int		is_metachar(char c);
int		token_get_state_50(char c);
int		token_get_state_51(char c);
int		token_get_state_52(char c);

//utils.c
void	ft_strcpy(char *prompt, char *copy);
void	token_add_to_list(t_list **token_list, char *lexeme, int token_type);
void	free_list(t_list **t_tree);
void	*ft_free_split(char **split);
void	init_shell(t_minishell *shell);

//parsing-tree
t_tree	*build_tree(t_list	*tkn_list);
t_list	*get_last_token(t_list	*tkn_list);
t_list	*hunt_last_pipe(t_list	*tkn_list);
t_tree	*build_root(t_list	*tkn_list);
void	build_branch(t_list *tkn_list, t_tree *pivot);
void	*free_tree(t_tree **tree);
t_list	*hunt_pipe_redir(t_list *tkn_list);
t_list	*hunt_redir(t_list	*tkn_list);

//validation.c
int		valid_redirect(t_list *list);
int		valid_pipe(t_list *token_list);
int		valid_list(t_list *list);

//builtin
// pwd.c
int		pwd(void);
//echo.c
int		echo(char **arg);
//change_directory.c
int		change_directory(t_envp **env_list, char *path);
void	update_pwd(t_envp **env_list, char *old_pwd, char *pwd);
int		check_path(char *path);
int		ft_exit(t_minishell *shell, char *arg);
int		check_exit_arg(char *arg);
//unset.c
int		unset(char *arg, t_envp **env_list);
void	remove_node_from_list(char *arg, t_envp **env_list);

//exec_builtin.c
int		aux_exec_builting(char *command, char **argv, t_minishell *shell);
int		is_builtin(t_tree *tree);
int		execute_builtin(t_minishell *shell);
void	get_args_builtin(t_list *sub_list, t_builtin *builtin);
void	init_builtin(t_builtin *builtin);
void	clear_args(char **args);

//env_list.c
t_envp	*env_create_node(void);
void	add_node_to_list(t_envp **head, t_envp *node);
t_envp	*node_from_environ(char *environ);
t_envp	*create_env_list(char **environ);
void	print_env_list(t_envp *env_list);
int		env(t_envp *env_list);
char	*envp_str(t_envp *env_list);
char	**list_to_str(t_envp *env_list);
int		count_nodes(t_envp *env_list);
void	free_env_list(t_envp *env_list);
void	free_envp_str(char	**envp);

//export.c
int		export_new_var(char **new_var, t_envp **env_list);
char	**new_var_split(char *arg);
char	*ft_getenv(char *arg, t_envp *env_list);
void	change_env_value(char *key, char *value, t_envp **env_list);
void	order_env_list(t_envp **env_list);
int		export(char *arg, t_envp **env_list);
int		check_arg(char	*arg);
int		check_key_name(char *key);

//signal.c
void	sig_handler_sigint(int signal);
void	signals_for_command(void);
//void	sig_handler_sigquit(int signal __attribute__((unused)));
int		control_sign(int new_signal);
void	init_signals(void);

#endif
