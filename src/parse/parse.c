/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:16:40 by shogura           #+#    #+#             */
/*   Updated: 2022/07/02 15:34:22 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_tree	*ast_new_node(char *nd_data, t_tree *left, t_tree *right, NodeType type)
{
	t_tree	*node;

	node = ft_calloc(1, sizeof(t_tree));
	if (node == NULL)
		return (NULL);

	return (NULL);
}
