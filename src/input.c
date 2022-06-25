/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:55 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 14:42:04 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	user_input(t_data *data)
{
	data->input = readline(PROMPT); //入力値の受取
	if (data->input == NULL)
		return ; // error
	if (ft_strlen(data->input) > 0)
		add_history(data->input); //コマンドがある場合historyに保存
	free(data->input);
}
