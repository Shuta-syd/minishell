/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 21:02:22 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <minishell.h>

//環境変数 単方向リスト （循環でも可）
typedef struct s_env
{
	char		*key;
	char		*val;
	struct s_env	*next;
}	t_env;

//字句解析 単方向リスト（循環でも可）
typedef struct s_token
{
	int			type;
	char		*token;
	struct s_token	*next;
}	t_token;

// 総合的なデータ群
typedef struct s_data
{
	char	**input;
	char	*path;
	char	**envp;
	pid_t	*ch_pid; //コマンド実行の際子プロセスのpid
	t_token	*lex_lst;
	t_env	*env_lst;
}	t_data;

#endif
