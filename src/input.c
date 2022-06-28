/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:55 by shogura           #+#    #+#             */
/*   Updated: 2022/06/28 18:59:59 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ctrl_d(void);

void	user_input(t_data *data)
{
	char	*input;

	input = readline(PROMPT); //入力値の受取
	if (input == NULL)
		ctrl_d();//Ctl+D error
	// if (ft_strlen(input) > 0)
	// 	add_history(input); //コマンドがある場合historyに保存
	data->input = ft_split(input, ' ');
	if (data->input == NULL)
		return ; //error
	free(input);
}

void	ctrl_d(void)
{
	write(1, "\b\b", 2);
	exit_(0);
}
