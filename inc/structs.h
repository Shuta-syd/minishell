/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/07/11 19:38:09 by shogura          ###   ########.fr       */
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

typedef enum
{
	TP_NORMAL,			   //囲まれていない
	EXPANDABLE_QUOTED, //""で囲まれてる;
	NOT_EXPANDABLE,	   //''で囲まれてる
	TP_PIPE,			   // |
	TP_DELIMITER,		   //;
	TP_REDIRECT
} LexType;

typedef struct s_token
{
	int			type;
	char		*token;
	struct s_token	*next;
}	t_token;

//抽象構文木（AST）
typedef enum
{
	ND_PIPE,				 // |
	ND_DEL,					 // ;
	ND_BRACE,				 // { }
	ND_BACKGROUND,	 //&
	ND_REDIRECT_IN,	 // <
	ND_HEREDOC, //heredoc EOS
	ND_REDIRECT_OUT_UPDATE, // >
	ND_REDIRECT_OUT_ADD, // >>
	ND_NL,					 // '\n'
	ND_CMD,			//cmd
	ND_DATA			 // data
} NodeType;

typedef struct s_ast
{
	NodeType	type;
	char		*nd_data; //type -> ND_DATAの時だけ格納、それ以外はNULL
	struct s_ast	*left;
	struct s_ast	*right;
} t_ast;

typedef struct s_data
{
	char	*input;
	char	**envp;
	pid_t	*ch_pid;
	t_token	*lex_lst;
	t_env	*env_lst;
	t_ast	*ast;
}	t_data;

#endif
