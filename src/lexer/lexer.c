/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/07/11 17:48:12 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	echo                "this is $USER"       'Hello $USER'
	↓
	echo "this is $USER" 'Hello $USER'
*/

void	lexer(t_data *data)
{
	printf("input->%s%s%s\n", GREEN, data->input, C_DEFAULT);
	store_lex_lst(data, &data->input);
	print_lex_lst(data->lex_lst);
}
