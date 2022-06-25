/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:32:51 by shogura           #+#    #+#             */
/*   Updated: 2022/06/26 01:51:20 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//include library
# include <stdio.h>
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
	t_token		*lex_lst;
	t_env		*env_lst;
} t_data;

//prototype
void	user_input(t_data *data);
void	lexer(t_data *data, char **input);

// lstope func
t_env	*env_node_new(char *env);
t_env	*get_env_last_node(t_env *env_lst);
void	env_node_add_back(t_env **env_lst, t_env *new_node);
t_token	*lex_node_new(char *token, int type);
t_token	*get_lex_last_node(t_token *lex_lst);
void	lex_node_add_back(t_token **lex_lst, t_token *new_node);
#endif

/*
	【メモ】
	・環境変数envをリスト構造で保持するのもあり
*/
