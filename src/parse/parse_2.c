/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:47:44 by shogura           #+#    #+#             */
/*   Updated: 2022/07/04 21:58:17 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>



t_ast *cmd(t_token **lex_lst)
{
	t_ast	*node;

	node = arg(lex_lst);
	return (node);
}

t_ast	*piped_cmd(t_token **lex_lst)
{
	t_ast	*node;

	node = cmd(lex_lst);
	if (has_meta_char(lex_lst, PIPE))
		node = ast_new_node(ND_PIPE, node, piped_cmd(lex_lst));
	return (node);
}

t_ast	*cmd_line(t_token **lex_lst)
{
	t_ast	*node;

	node = piped_cmd(lex_lst);
	if (has_meta_char(lex_lst, DEL))
		node = ast_new_node(ND_CMD, node, piped_cmd(lex_lst));
	return (node);
}
