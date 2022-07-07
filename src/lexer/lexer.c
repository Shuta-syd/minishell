/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 22:39:11 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	DELIMITERS ";|{}$&\'\"'\n'<> "

	DELIMITERSが来たら区切る

	例
	cat < file | grep a | wc -l > file2 > file3; echo a
	echo "hello w"'orld'; cat<file|wc -> 14 + 1
	echo "This is $USER"  'This is $USER' ->
	cat<file|grep 42|wc;echo "This is $USER";
	cat<file|grep 42|wc;echo 'This is $USER';

	" "のなかにある空白の扱い
*/

void	lexer(t_data *data)
{
	char	*input;

	input = del_white_space(data->input);
	printf("input->%s%s%s\n", GREEN, input, C_DEFAULT);
	free(data->input);
	data->input = input;
	store_lex_lst(data, &input);
	print_lex_lst(data->lex_lst);
}
