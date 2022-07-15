/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/07/15 14:32:27 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct s_cmd
{
	char	**argv;
}	t_cmd;

typedef struct s_shell
{
	char			*input;
	struct s_cmd	*cmds;
	uint32_t		cmd_cnt;
	char			*infile;
	char			*outfile;
}	t_shell;

#endif
