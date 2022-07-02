/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/07/02 15:34:26 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct s_env
{
	char		*key;
	char		*val;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	int			type;
	char		*token;
	struct s_token	*next;
}	t_token;

//抽象構文木（AST）
typedef enum
{
	ND_PIPE,  // |
	ND_SEM,	   // ;
	ND_DOLLAR, // $
	ND_BG, //&
	ND_REDIRECT_IN, // >
	ND_REDIRECT_OUT, // <
	ND_DATA // data
} NodeType;

typedef struct s_tree
{
	NodeType	type;
	char		*nd_data; //type -> ND_DATAの時だけ格納、それ以外はNULL
	struct s_tree	*left;
	struct s_tree	*right;

} t_tree;

typedef struct s_data
{
	char	**input;
	char	**envp;
	pid_t	*ch_pid;
	t_token	*lex_lst;
	t_env	*env_lst;
}	t_data;

#endif
