/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:21:17 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/26 08:56:44 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	go_home(t_shell *shell);

int	ft_cd(char *dir, t_shell *shell)
{
	if (dir == NULL || ft_strcmp(dir, "~") == 0)
		return (go_home(shell));
	else if (chdir(dir) != 0)
	{
		perror(dir);
		return (1);
	}
	return (0);
}

static int	go_home(t_shell *shell)
{
	if (chdir(ms_getenv(shell, "HOME")) != 0)
	{
		ft_putstr("can't found $HOME\n");
		return (1);
	}
	return (0);
}