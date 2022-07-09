/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:16:40 by shogura           #+#    #+#             */
/*   Updated: 2022/07/09 22:49:53 by shogura          ###   ########.fr       */
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
	data->ast = cmd_line(&lex_lst);
	if (has_meta_char(&lex_lst, DEL))
	{
		node = ast_new_node(ND_NL, NULL, NULL);
		data->ast = ast_new_node(ND_DEL, data->ast, node);
	}
	else
		data->ast = ast_new_node(ND_NL, data->ast, NULL);
}
