/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/07/16 18:04:10 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

/*
	list structure for managing environment variables
*/
typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
} t_env;

/*
	structure that holds information on each command
*/
typedef struct s_cmd
{
	char	**args;
}	t_cmd;

/*
	structure for command execution
*/
typedef struct s_exe
{
	struct s_cmd	*cmds;
	char			*infile;
	char			*outfile;
	uint32_t		cmd_cnt;
} t_exe;

/*
	structure that holds all information in this shell
*/
typedef struct s_shell
{
	char	*input;
	t_exe	*exe;
	t_env	*env_lst;
}	t_shell;

#endif
