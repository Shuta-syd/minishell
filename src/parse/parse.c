/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:16:40 by shogura           #+#    #+#             */
/*   Updated: 2022/07/02 22:36:01 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_tree	*ast_new_node(char *nd_data, t_tree *left, t_tree *right, NodeType type)
{
	t_tree	*node;

	node = ft_calloc(1, sizeof(t_tree));
	if (node == NULL)
		return (NULL);
	node->left = left;
	node->right = right;
	node->type = type;
	node->nd_data = nd_data;
	return (node);
}

void	parse(t_data *data)
{
	t_token	*lex_lst;
	t_tree	*ast_tree;

	lex_lst = data->lex_lst;
	ast_tree = data->ast_tree;
	
}
