/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:32:51 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 14:19:59 by shogura          ###   ########.fr       */
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

//字句解析 リスト 単方向（循環でも可）
typedef struct s_lexical_lst
{
	char	*lex; //一意の入力値
	struct s_lexcical_lst	*next;
}	t_lexical_lst;

// 総合的なデータ群
typedef struct s_data
{
	char	*input;
	char	**envp;
	t_lexical_lst	lex;
}	t_data;

#endif
