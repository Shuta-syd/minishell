/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:07:33 by shogura           #+#    #+#             */
/*   Updated: 2022/07/06 16:39:47 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_meta_char(t_token **lex_lst, char *meta_ch)
{
	while (*meta_ch)
	{
		if (ft_strchr((*lex_lst)->token, *meta_ch))
		{
			*lex_lst = (*lex_lst)->next;
			return (true);
		}
		meta_ch++;
	}
	return (false);
}

void	print_ast_tree(t_ast *ast)
{
	if (ast->left)
		print_ast_tree(ast->left);
	printf("NodeType->[%d] nd_data->[%s] me->[%p] left->[%p] right->[%p]\n", ast->type, ast->nd_data, ast, ast->left, ast->right);
	if (ast->right)
		print_ast_tree(ast->right);
}
