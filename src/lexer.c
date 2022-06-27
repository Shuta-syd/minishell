/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 20:52:31 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// 字句解析のための関数
void	lexer(t_data *data, char **input)
{
	store_lex_lst(data, input);
	//if(メタ文字がなかった場合)
	// do_single_command(data);
}
/*
	1. メタ文字なしのシングルコマンドの実装
*/
