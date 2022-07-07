/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:05 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/07 23:03:55 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_all(t_data *data)
{
	size_t i;

	i = 0;
	// free_ast(&data->ast);
	free_lex_lst(data);
	if (data->input == NULL)
		return ;
	free(data->input);
}

void	mem_free(void **mem)
{
	
}
