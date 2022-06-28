/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:32:51 by shogura           #+#    #+#             */
/*   Updated: 2022/06/28 21:35:54 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//include library
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libft.h>
# include "struct.h"
# include "builtin.h"
# include "lst_ope.h"
# include "signal.h"

# define PROMPT "gosh$ "
# define METACHAR ";|&`\"'\\<>()[]{}"
# define NOTYPE 0

void free_all(t_data *data);
void user_input(t_data *data);
void	lexer(t_data *data, char **input);

//execute func
void	do_single_command(t_data *data);

#endif
