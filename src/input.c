/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:55 by shogura           #+#    #+#             */
/*   Updated: 2022/07/06 16:26:14 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


void	user_input(t_data *data)
{
	char	*input;

	//input = readline(PROMPT);
	input = ft_strdup("cat > file | grep a | wc \n");
	if (input == NULL)
		ctrl_d();
	/*
		if (ft_strlen(input) > 0)
			add_history(input); //コマンドがある場合historyに保存
	*/
	data->input = ft_split(input, ' ');
	free(input);
	if (data->input == NULL)
		return ;
}
