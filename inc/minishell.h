/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:32:51 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 15:46:12 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//include library
# include <stdio.h>
# include <stdbool.h>
# include <libft.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "gosh$ "
# define META ";|&`\"'\\<>()[]{}"
# define NOTYPE 0

//環境変数 単方向リスト （循環でも可）
typedef struct s_env
{
	char		*val;
	struct	s_env *next;
} t_env;

//字句解析 単方向リスト（循環でも可）
typedef struct s_token
{
	int		type;
	char	*token;
	struct s_token	*next;
}	t_token;

// 総合的なデータ群
typedef struct s_data
{
	char		**input;
	char		*path_val;
	pid_t		*ch_pid; //コマンド実行の際子プロセスのpid
	t_token		*lex_lst;
	t_env		*env_lst;
} t_data;

//
void	user_input(t_data *data);
void	lexer(t_data *data, char **input);

//execute func
void	do_single_command(t_data *data);

// lstope func
t_env	*env_node_new(char *env);
t_env	*get_env_last_node(t_env *env_lst);
void	env_node_add_back(t_env **env_lst, t_env *new_node);
void	store_env_lst(t_data *data, char **envp);
void	free_env_lst(t_env *env_lst);
void	search_path_from_env(t_data *data);

t_token *lex_node_new(char *token, int type);
t_token	*get_lex_last_node(t_token *lex_lst);
void	lex_node_add_back(t_token **lex_lst, t_token *new_node);
void	store_lex_lst(t_data *data, char **input);
void	free_lex_lst(t_token *lex_lst);
#endif
