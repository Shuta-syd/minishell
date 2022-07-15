/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/07/15 17:44:45 by shogura          ###   ########.fr       */
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

*/
typedef struct s_cmd
{
	char	**args;
	char	*infile;
	char	*outfile;
}	t_cmd;

/*
	Structure for command execution
*/
typedef struct s_exe
{
	struct s_cmd	*cmds;
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
