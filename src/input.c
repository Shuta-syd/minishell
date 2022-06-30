/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:55 by shogura           #+#    #+#             */
/*   Updated: 2022/06/30 18:11:35 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ctrl_d(void);

void	user_input(t_data *data)
{
	char	*input;

	input = readline(PROMPT);
	if (input == NULL)
		ctrl_d();
	data->input = ft_split(input, ' ');
	if (data->input == NULL)
		return ;
	free(input);
}

void	ctrl_d(void)
{
	write(1, "\b\b", 2);
	exit_(0);
}
