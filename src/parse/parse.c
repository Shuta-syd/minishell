/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:16:40 by shogura           #+#    #+#             */
/*   Updated: 2022/07/06 17:23:31 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	parse()は抽象構文木（再起下降構文解析法）を作成する
	BNF記法の非終端文字で関数分けを行なっている
*/

void	parse(t_data *data)
{
	t_ast		*node;
	t_token	*lex_lst;

	node = NULL;
	lex_lst = data->lex_lst;
	data->ast_tree = cmd_line(&lex_lst);
	if (has_meta_char(&lex_lst, DEL))
	{
		node = ast_new_node(ND_NL, NULL, NULL);
		data->ast_tree = ast_new_node(ND_DEL, data->ast_tree, node);
	}
	else
		data->ast_tree = ast_new_node(ND_NL, data->ast_tree, NULL);
	putchar('\n');
	print_ast_tree(data->ast_tree);
}
