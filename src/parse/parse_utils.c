/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:07:33 by shogura           #+#    #+#             */
/*   Updated: 2022/07/06 18:12:38 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_meta_char(t_token **lex_lst, char *meta_ch)
{
	while (*lex_lst && *meta_ch)
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


// to debug
void	print_ast_tree(t_ast *ast)
{
	if (ast->left)
		print_ast_tree(ast->left);
	printf("NodeType->[%s%d%s] nd_data->[%s%s%s] me->[%s%p%s] left->[%s%p%s] right->[%s%p%s]\n", GREEN,ast->type,C_DEFAULT, GREEN, ast->nd_data, C_DEFAULT, GREEN,ast, C_DEFAULT, GREEN,ast->left, C_DEFAULT, GREEN, ast->right, C_DEFAULT);
	if (ast->right)
		print_ast_tree(ast->right);
}
