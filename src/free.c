/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:05 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/09 22:41:07 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_all(t_data *data)
{
	free_ast(data);
	free_lex_lst(data);
	if (data->input == NULL)
		return ;
	free(data->input);
}
