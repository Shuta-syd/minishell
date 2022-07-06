/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:47:44 by shogura           #+#    #+#             */
/*   Updated: 2022/07/06 15:11:20 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	t_astにおいてredirectをどのように扱うか
	> >> < << を全て分けて考えるべきか

	[メモ]
	関数のフォーマットが同じなら関数ポインタなどで代用できるかも
*/
t_ast *redirect(t_token **lex_lst, char *redirect_token)
{
	t_ast	*node;

	if (strcmp(redirect_token, ">"))
		node = ast_new_node_no_child_node(ND_REDIRECT_OUT_UPDATE);
	else if (strcmp(redirect_token, ">>"))
		node = ast_new_node_no_child_node(ND_REDIRECT_OUT_ADD);
	else if (strcmp(redirect_token, "<"))
		node = ast_new_node_no_child_node(ND_REDIRECT_IN);
	else if (strcmp(redirect_token, "<<"))
		node = ast_new_node_no_child_node(ND_HEREDOC);
	return (node);
}

t_ast	*cmd(t_token **lex_lst)
{
	t_ast *node;
	char	*redirect_token;

	redirect_token = (*lex_lst)->token;
	if (has_meta_char(lex_lst, REDIRECT))
	{
		node = redirect(lex_lst, redirect_token);
		node = ast_new_node(ND_REDIRECT_IN, node, cmd(lex_lst));
		return node;
	}
	node = ast_new_node_nd_data(lex_lst);
	if (has_meta_char(lex_lst, META) == false)
		node = ast_new_node(ND_DATA, node, cmd(lex_lst));
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
		node = ast_new_node(ND_DEL, node, cmd_line(lex_lst));
	return (node);
}
