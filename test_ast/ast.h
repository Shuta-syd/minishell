/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:18:47 by shogura           #+#    #+#             */
/*   Updated: 2022/07/04 20:19:47 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/inc/libft.h"

typedef enum
{
	ND_ADD,	 // +
	ND_MUL,	 // *
	ND_DELI, // ;
	ND_CMD,	 // cmd
	ND_NUM,	 // int
	ND_VAL   //cmd name
}
NodeKind;

typedef struct s_ast
{
	NodeKind	kind;
	struct s_ast *left;
	struct s_ast *right;
	int	num;
	char	*val;
} t_ast;

t_ast *primary(char **input);
t_ast *mul(char **input);
t_ast *expr(char **input);
t_ast *cmd(char **input);
t_ast *seq_cmd(char **input);
t_ast *cmd_line(char **input);
t_ast *input(char *input);

#endif
