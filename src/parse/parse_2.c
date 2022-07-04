/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:47:44 by shogura           #+#    #+#             */
/*   Updated: 2022/07/04 22:24:44 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	t_astにおいてredirectをどのように扱うか
	> >> < << を全て分けて考えるべきか
*/
t_ast	*arg(t_token **lex_lst)
{
	t_ast	*node;

	if (has_meta_char(lex_lst, REDIRECT))
	{
		node = redirect(lex_lst);
		node = ast_new_node(ND_REDIRECT_IN, node, arg(lex_lst));
		return node;
	}
	node = ast_new_node_nd_data((*lex_lst)->token);
	if (has_meta_char(lex_lst, META) == false)//さらにargがある場合 条件-> META文字以外
		node = ast_new_node(ND_DATA, node, arg(lex_lst));
	return (node);
}

t_ast	*cmd(t_token **lex_lst)
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
