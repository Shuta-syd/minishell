/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:15:10 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 17:39:25 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*search_path_from_env(t_env *env_lst)
{
	bool	is_path;
	char	*path_val;

	while (env_lst)
	{
		is_path = ft_strstr(env_lst->val, "PATH");
		if (is_path)
		{
			path_val = env_lst->val;
			return (path_val);
		}
		env_lst = env_lst->next;
	}
	return (NULL);
}

//環境変数PATHから外部コマンドの実行ファイルを探索する
void	search_command_from_path(t_data *data)
{
	
}

void	do_single_command(t_data *data)
{
	search_command_from_path(data);
}
