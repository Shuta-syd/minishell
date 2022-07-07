/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:55 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 11:18:59 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


void	user_input(t_data *data)
{
	// data->input = readline(PROMPT);
	data->input = ft_strdup("cat file | grep a | wc");
	if (data->input == NULL)
		ctrl_d();
	if (ft_strlen(data->input) > 0)
		add_history(data->input);
}
