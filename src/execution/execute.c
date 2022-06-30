/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:15:10 by shogura           #+#    #+#             */
/*   Updated: 2022/06/30 18:53:06 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_paths(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*search_exe_from_path(t_data *data)
{
	size_t	i;
	char	**paths;
	char	*path;
	char	*exe_file;

	i = 0;
	paths = ft_split(ms_getenv(data, "PATH"), ':');
	if (paths == NULL)
		return (NULL);
	if (access(data->lex_lst->token, X_OK) == 0)
	{
		free_paths(paths);
		return (data->lex_lst->token);
	}
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		exe_file = ft_strjoin(path, data->lex_lst->token);
		free(path);
		if (access(exe_file, X_OK) == 0)
		{
			free_paths(paths);
			return (exe_file);
		}
		free(exe_file);
		i++;
	}
	free_paths(paths);
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
		return ; // error
	else if (ch_pid == 0)
		execve(exe_file, &data->lex_lst->token, NULL);
	free(exe_file);
	wait(0);
}
