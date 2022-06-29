/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:15:10 by shogura           #+#    #+#             */
/*   Updated: 2022/06/29 19:55:21 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// /環境変数PATHから外部コマンドの実行ファイルを探索する
char	*search_exe_from_path(t_data *data)
{
	size_t	i;
	char	**paths;
	char	*path;
	char	*exe_file;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	if (paths == NULL)
		return (NULL);//error
	if (access(data->lex_lst->token, X_OK) == 0)
		return (data->lex_lst->token);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		exe_file = ft_strjoin(path, data->lex_lst->token);
		free(path);
		if (access(exe_file, X_OK) == 0)
			return (exe_file);
		free(exe_file);
		i++;
	}
	perror("gosh: ");
	return (NULL);
}

void	do_single_command(t_data *data)
{
	pid_t	ch_pid;
	char	*exe_file;

	if (data->lex_lst == NULL)
		return ;
	exe_file = search_exe_from_path(data);
	if (exe_file == NULL)
		return ;
	ch_pid = fork();
	if (ch_pid == -1)
		return ;  // error
	else if (ch_pid == 0)
		execve(exe_file, &data->lex_lst->token, NULL);
	free(exe_file);
	wait(0);
}
