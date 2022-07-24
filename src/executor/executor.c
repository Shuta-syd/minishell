/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:52:43 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/24 17:56:07 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execution_loop(t_shell *shell, int *tmpout, pid_t *pid);
static void	operate_outfile(t_shell *shell, int *tmpout);

void	executor(t_shell *shell)
{
	int			tmpin;
	int			tmpout;
	pid_t		pid;

	tmpin = dup(0);
	tmpout = dup(1);
	if (shell->exe->infile)
		shell->exe->fd[IN] = open(shell->exe->infile, O_RDONLY);
	else
		shell->exe->fd[IN] = dup(tmpin);
	execution_loop(shell, &tmpout, &pid);
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	waitpid(pid, NULL, 0);
}

static void	execution_loop(t_shell *shell, int *tmpout, pid_t *pid)
{
	uint32_t	i;

	i = 0;
	while (i < shell->exe->cmd_cnt)
	{
		dup2(shell->exe->fd[IN], 0);
		close(shell->exe->fd[IN]);
		if (i == shell->exe->cmd_cnt - 1)
			operate_outfile(shell, tmpout);
		else
		{
			pipe(shell->exe->pipe_fd);
			shell->exe->fd[IN] = shell->exe->pipe_fd[IN];
			shell->exe->fd[OUT] = shell->exe->pipe_fd[OUT];
		}
		dup2(shell->exe->fd[OUT], 1);
		close(shell->exe->fd[OUT]);
		*pid = fork();
		if (*pid == 0)
		{
			if (ft_execvp(shell->exe->cmds[i].args[0], shell->exe->cmds[i].args, shell) != 0)
				perror(shell->exe->cmds[i].args[0]);
			exit(1);
		}
		i++;
	}
}

static void	operate_outfile(t_shell *shell, int *tmpout)
{
	if (shell->exe->outfile)
	{
		if (shell->exe->outfile_mode == TRUNC)
			shell->exe->fd[OUT] = open(shell->exe->outfile,
					O_RDWR | O_CREAT | O_TRUNC, 0644);
		else if (shell->exe->outfile_mode == APPEND)
			shell->exe->fd[OUT] = open(shell->exe->outfile,
					O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
		shell->exe->fd[OUT] = dup(*tmpout);
}
