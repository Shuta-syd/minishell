/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 19:16:33 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//入力値のリスト化
static void	store_token_lst(t_data *data, char **input)
{
	t_token	*prev;
	t_token	*tmp;
	size_t	i;

	i = 0;
	while (input[i])
	{
		tmp = ft_calloc(1, sizeof(t_token));
		if (tmp == NULL)
			return; // error
		tmp->type = NOTYPE;
		tmp->token = ft_strdup(input[i]);
		if (tmp->token == NULL)
			return; // error
		tmp->next = NULL;
		if (i == 0)
			data->lex = tmp;
		else
			prev->next = tmp;
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
}

// 字句解析のための関数
void	lexer(t_data *data, char **input)
{
	store_token_lst(data, input);
	//if(メタ文字がなかった場合)
	excute_single_command(data);
}
/*
	1. メタ文字なしのシングルコマンドの実装
*/
