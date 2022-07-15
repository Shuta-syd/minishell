/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:52:43 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/15 21:35:52 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static	void	operate_outfile(t_shell *shell, int *tmpout)
{
	if (shell->outfile)
	{
		if (shell->outfile_mode == TRUNC)
			shell->fd[OUT] = open(shell->outfile,
					O_RDWR | O_CREAT | O_TRUNC, 0644);
		else if (shell->outfile_mode == APPEND)
			shell->fd[OUT] = open(shell->outfile,
					O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
		shell->fd[OUT] = dup(*tmpout);
}

static void	execution_loop(t_shell *shell, int *tmpout, pid_t *pid)
{
	uint32_t	i;

	i = 0;
	while (i < shell->cmd_cnt)
	{
		dup2(shell->fd[IN], 0);
		close(shell->fd[IN]);
		if (i == shell->cmd_cnt - 1)
			operate_outfile(shell, tmpout);
		else
		{
			pipe(shell->pipe_fd);
			shell->fd[IN] = shell->pipe_fd[IN];
			shell->fd[OUT] = shell->pipe_fd[OUT];
		}
		dup2(shell->fd[OUT], 1);
		close(shell->fd[OUT]);
		*pid = fork();
		if (*pid == 0)
		{
			ft_execvp(shell->cmds[i].argv[0], shell->cmds[i].argv);
			perror(shell->cmds[i].argv[0]);
		}
		i++;
	}
}

void	executor(t_shell *shell)
{
	int			tmpin;
	int			tmpout;
	pid_t		pid;

	tmpin = dup(0);
	tmpout = dup(1);
	if (shell->infile)
		shell->fd[IN] = open(shell->infile, O_RDONLY);
	else
		shell->fd[IN] = dup(tmpin);
	execution_loop(shell, &tmpout, &pid);
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	waitpid(pid, NULL, 0);
}
