/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:52:43 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/26 09:28:59 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execution_loop(t_shell *shell, int *tmpout, pid_t *pid);
static void	operate_outfile(t_shell *shell, int *tmpout);
static void	execute(t_shell *shell, pid_t *pid, int i);
static bool	do_builtins(char *file, char **argv, t_shell *shell);

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
	waitpid(pid, &g_status, 0);
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
		execute(shell, pid, i);
		i++;
	}
}

static void	execute(t_shell *shell, pid_t *pid, int i)
{
	char	*file;
	char	**argv;

	file = shell->exe->cmds[i].args[0];
	argv = shell->exe->cmds[i].args;
	if (file == NULL)
		return ;
	if (do_builtins(file, argv, shell) == true)
		return ;
	else
	{
		*pid = fork();
		if (*pid == 0)
		{
			if (ft_execvp(file, argv, shell) != 0)
				perror(file);
			exit(1);
		}
	}
}

static bool	do_builtins(char *file, char **argv, t_shell *shell)
{
	if (ft_strcmp(file, "echo") == 0)
		g_status = ft_echo(argv);
	else if (ft_strcmp(file, "env") == 0)
		ft_env(shell);
	else if (ft_strcmp(file, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(file, "cd") == 0)
		g_status = ft_cd(argv[1], shell);
	else if (ft_strcmp(file, "exit") == 0)
		exit_("exit", EXIT_SUCCESS);
	else if (ft_strcmp(file, "export") == 0)
		g_status = ft_export(shell, argv[1]);
	else if (ft_strcmp(file, "unset") == 0)
		ft_unset(shell, argv[1]);
	else
		return (false);
	return (true);
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
