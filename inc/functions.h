/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:11:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/07 22:58:41 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "minishell.h"

//utils
char	*ms_getenv(t_data *data, char *name);
void	free_all(t_data *data);
void	motd(void);

//input
void	user_input(t_data *data);
void	set_signal(void);

//lexer
size_t	count_len_deled_str(char *input);
bool	is_delimiter_prev_next(char *input);
char	*del_white_space(char *input);
char	*fetch_word(char **input);
char	*fetch_deli(char **input);
void	lexer(t_data *data);

//parser
void	parse(t_data *data);
bool	has_meta_char(t_token **lex_lst, char *meta_char);
t_ast	*cmd_line(t_token **lex_lst);
t_ast	*piped_cmd(t_token **lex_lst);
t_ast	*cmd(t_token **lex_lst);
t_ast	*redirect(t_token **lex_lst, char *redirect_token);
void	print_ast(t_ast *ast);

// execution
void	do_single_command(t_data *data);

//builtins
void	cd(t_data *data);
void	env(t_data *data);
void	exit_(int status);

//signal
void	ctrl_d(void);

// list funcs
t_env	*env_node_new(char *env);
t_env	*get_env_last_node(t_env *env_lst);
void	env_node_add_back(t_env **env_lst, t_env *new_node);
void	store_env_lst(t_data *data, char **envp);
void	free_env_lst(t_env *env_lst);

t_token	*lex_node_new(char *token, int type);
t_token	*get_lex_last_node(t_token *lex_lst);
void	lex_node_add_back(t_token **lex_lst, t_token *new_node);
void	store_lex_lst(t_data *data, char **input);
void	free_lex_lst(t_data *data);
void	print_lex_lst(t_token *lex_lst);

t_ast	*ast_new_node(NodeType type, t_ast *left, t_ast *right);
t_ast	*ast_new_node_nd_data(t_token **lex_lst);
t_ast	*ast_new_node_no_child_node(NodeType type);
void	free_ast(t_ast **ast);

#endif
