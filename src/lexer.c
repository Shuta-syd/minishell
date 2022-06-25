/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/06/26 01:53:35 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//入力値のリスト化
static void	store_lex_lst(t_data *data, char **input)
{
	size_t	i;
	t_token	*new_node;

	i = 1;
	data->lex_lst = lex_node_new(input[0], NOTYPE);
	if (data->lex_lst == NULL)
		return ; //error
	while (input[i])
	{
		new_node = lex_node_new(input[i], NOTYPE);
		if (new_node == NULL)
			return ; //error
		lex_node_add_back(&data->lex_lst, new_node);
		i++;
	}
}

// 字句解析のための関数
void	lexer(t_data *data, char **input)
{
	store_lex_lst(data, input);
	while (data->lex_lst)
	{
		printf("token->%s type->%d\n", data->lex_lst->token, data->lex_lst->type);
		data->lex_lst = data->lex_lst->next;
	}

	//if(メタ文字がなかった場合)
	// excute_single_command(data);
}
/*
	1. メタ文字なしのシングルコマンドの実装
*/
