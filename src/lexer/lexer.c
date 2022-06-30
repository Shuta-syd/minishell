/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/06/30 19:21:34 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lexer(t_data *data, char **input)
{
	store_lex_lst(data, input);
	print_lex_lst(data->lex_lst);
	do_single_command(data);
}
