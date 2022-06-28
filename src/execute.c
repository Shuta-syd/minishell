/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:15:10 by shogura           #+#    #+#             */
/*   Updated: 2022/06/28 21:03:30 by shogura          ###   ########.fr       */
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
	//error function
	perror("gosh: ");
	return (NULL);
}

void	child_process(t_data *data)
{
	char	*exe_file;

	exe_file =  search_exe_from_path(data);
	execve(exe_file, &data->lex_lst->token, NULL);
}

void	do_single_command(t_data *data)
{
	pid_t	ch_pid;

	ch_pid = fork();
	if (ch_pid == -1)
		return ;  // error
	else if (ch_pid == 0)
		child_process(data);
	wait(0);
}
