/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/07/08 18:22:53 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
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
