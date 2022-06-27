/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:15:10 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 15:46:02 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//環境変数PATHから外部コマンドの実行ファイルを探索する
void	search_command_from_path(t_data *data)
{
	
}

void	do_single_command(t_data *data)
{
	search_command_from_path(data);
}
