/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:32:51 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 19:17:10 by shogura          ###   ########.fr       */
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
# define NOTYPE 0;

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
	char	**input;
	t_token	*lex;
	t_env		*env;
} t_data;

//prototype
void	user_input(t_data *data);
void	lexer(t_data *data, char **input);
void	excute_singul_command(t_data *data);
#endif

/*
	【メモ】
	・環境変数envをリスト構造で保持するのもあり
*/
