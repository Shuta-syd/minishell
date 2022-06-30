/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:56 by shogura           #+#    #+#             */
/*   Updated: 2022/06/30 18:31:08 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <minishell.h>

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

typedef struct s_data
{
	char	**input;
	char	**envp;
	pid_t	*ch_pid;
	t_token	*lex_lst;
	t_env	*env_lst;
}	t_data;

#endif
