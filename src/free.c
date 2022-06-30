/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:05 by tharaguc          #+#    #+#             */
/*   Updated: 2022/06/30 18:07:07 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_all(t_data *data)
{
	size_t i;

	i = 0;
	free_lex_lst(data->lex_lst);
	if (data->input == NULL)
		return ;
	while (data->input[i])
	{
		free(data->input[i]);
		i++;
	}
	free(data->input);
}