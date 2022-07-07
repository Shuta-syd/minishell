/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:32:51 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 22:35:45 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libft.h>

# include "color.h"
# include "structs.h"
# include "functions.h"

# define PROMPT "gosh$ "
# define NOTYPE 0

//lexer
# define DELIMITERS "-;|{}&'\n'<> "

//parse
# define META ";|{}$&\'\"'\n'"
# define DEL ";"
# define PIPE "|"
# define REDIRECT "<>"

#endif
