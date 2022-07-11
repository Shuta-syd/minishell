/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:47:44 by shogura           #+#    #+#             */
/*   Updated: 2022/07/11 19:55:27 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_ast	*redirect(t_token **lex_lst, char *redirect_token)
{
	t_ast	*node;

	if (strcmp(redirect_token, ">") == 0)
		node = ast_new_node_no_child_node(ND_REDIRECT_OUT_UPDATE);
	else if (strcmp(redirect_token, ">>") == 0)
		node = ast_new_node_no_child_node(ND_REDIRECT_OUT_ADD);
	else if (strcmp(redirect_token, "<") == 0)
		node = ast_new_node_no_child_node(ND_REDIRECT_IN);
	else if (strcmp(redirect_token, "<<") == 0)
		node = ast_new_node_no_child_node(ND_HEREDOC);
	return (node);
}

t_ast	*cmd(t_token **lex_lst)
{
	t_ast		*node;
	t_token	*tmp;
	char		*redirect_token;

	if (*lex_lst)
		redirect_token = (*lex_lst)->token;
	else
		return (NULL);
	if (has_meta_char(lex_lst, "<>"))
	{
		node = redirect(lex_lst, redirect_token);
		node = ast_new_node(ND_CMD, node, cmd(lex_lst));
		return node;
	}
	node = ast_new_node_nd_data(lex_lst);
	tmp = *lex_lst;
	if (has_meta_char(lex_lst, "; |\n "))
		*lex_lst = tmp;
	else
		node = ast_new_node(ND_CMD, node, cmd(lex_lst));
	return (node);
}

t_ast	*piped_cmd(t_token **lex_lst)
{
	t_ast	*node;

	node = cmd(lex_lst);
	if (has_meta_char(lex_lst, "|"))
		node = ast_new_node(ND_PIPE, node, piped_cmd(lex_lst));
	return (node);
}

t_ast	*cmd_line(t_token **lex_lst)
{
	t_ast	*node;

	node = piped_cmd(lex_lst);
	if (has_meta_char(lex_lst, ";"))
		node = ast_new_node(ND_DEL, node, cmd_line(lex_lst));
	return (node);
}
