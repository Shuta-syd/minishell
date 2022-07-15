/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/07/14 12:54:09 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

/*
	enum for determining the type of string in t_cmd
	T_CMD:	   ex) cat, echo, wc, grep
	T_ARG:	   ex) 42, filename
	T_PIPE:	   ex) |
	T_REDIRECT:  ex) >, >>, <, <<
	T_DELIMITER: ex) ;
*/
typedef enum
{
	T_CMD,
	T_ARG,
	T_PIPE,
	T_REDIRECT,
	T_DELIMITER
}	StrType;

/*
	list structure for managing environment variables
*/
typedef struct s_env
{
	char		*key;
	char		*val;
	struct s_env	*next;
}	t_env;

/*
	structure to manage user input（struct name is needed to change）
	type except for T_ARG -> char *cmd
	type T_ARG - char **args
*/
typedef struct s_cmd
{
	StrType			type;
	char			*cmd;
	char			**args;
	struct s_cmd	*next;
} t_cmd;

/*
	structure that holds all information in this shell
*/
typedef struct s_data
{
	char		*input;
	int			exit_status;
	t_env		*env_lst;
	t_cmd		**cmd_lst;
} t_data;

#endif

/*
echo "This is $USER" 'Hello $USER'
cat < file
	grep 42
		wc



[[This is shogura][ ][Hello $USER]]

grep hello
execve(/bin/grep, [[grep][hello]], NULL)
*/
