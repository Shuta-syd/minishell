/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:24:20 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/14 22:55:02 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_abs_exe(char *file, char **paths);
static void	free_dp(char **dp);

int	ft_execvp(char *file, char *argv[])
{
	char		**paths;
	extern char	**environ;

	paths = ft_split(getenv("PATH"), ':');
	file = get_abs_exe(file, paths);
	if (file == NULL)
		return (-1);
	free_dp(paths);
	execve(file, argv, environ);
	return (-1);
}

static char	*get_abs_exe(char *file, char **paths)
{
	char	*tmp;
	char	*abs;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		abs = ft_strjoin(tmp, file);
		free(tmp);
		if (access(abs, X_OK) == 0)
			return (abs);
		else
			free(abs);
		i++;
	}
	return (NULL);
}

static void	free_dp(char **dp)
{
	size_t	i;

	i = 0;
	while (dp[i])
		free(dp[i++]);
	free(dp);
}
