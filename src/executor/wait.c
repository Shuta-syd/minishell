/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:05:30 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/27 19:18:41 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_processes(t_shell *shell)
{
	int		status;
	size_t	i;

	i = 0;
	status = 0;
	while (i++ < shell->exe->cmd_cnt)
		wait(&status);
	if (status == SIGINT)
		g_status = SIGINT + 128;
	else if (status == SIGQUIT)
		g_status = SIGQUIT + 128;
	else
		g_status = WEXITSTATUS(status);
}
