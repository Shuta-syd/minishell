/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:32:51 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 16:28:50 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//include library
# include <stdio.h>
# include <libft.h>
# include <readline/readline.h>
# include <readline/history.h>

#define PROMPT "gosh$ "

//環境変数 単方向リスト （循環でも可）
typedef struct s_env
{
	char		*val;
	struct	s_env *next;
} t_env;

//字句解析 単方向リスト（循環でも可）
typedef struct s_token
{
	int		meta; //メタ文字種類（先頭は0）
	char	*lex; //一意の入力値
	struct s_token	*next;
}	t_token;

// 総合的なデータ群
typedef struct s_data
{
	char	*input;
	char	**envp;
	t_token	lex;
	t_env		env;
} t_data;

//prototype
void	user_input(t_data *data);
void	lexer(t_data *data);
#endif

/*
	【メモ】
	・環境変数envをリスト構造で保持するのもあり
*/
