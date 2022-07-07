/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_lst_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:49:19 by shogura           #+#    #+#             */
/*   Updated: 2022/07/06 17:58:40 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_ast	*ast_new_node(NodeType type, t_ast *left, t_ast *right)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (node == NULL)
		return (NULL);
	node->left = left;
	node->right = right;
	node->type = type;
	node->nd_data = NULL;
	return (node);
}

t_ast	*ast_new_node_nd_data(t_token **lex_lst)
{
	t_ast	*node;

	if (*lex_lst == NULL)
		return (NULL);
	node = ft_calloc(1, sizeof(t_ast));
	node->type = ND_DATA;
	node->nd_data = (*lex_lst)->token;
	*lex_lst = (*lex_lst)->next;
	return (node);
}

t_ast	*ast_new_node_no_child_node(NodeType type)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->type = type;
	node->nd_data = NULL;
	return (node);
}
