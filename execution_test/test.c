/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:11:07 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/15 14:32:14 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "libft.h"

int	ft_execvp(char *file, char *argv[]);


typedef struct s_cmd
{
	char **argv;
}	t_cmd;

typedef struct s_shell
{
	struct s_cmd	*cmds;
	uint32_t		cmd_cnt;
	char			*infile;
	char			*outfile;
}	t_shell;



void	execution(t_shell *shell);

int main(void)
{
	t_shell	shell;
	shell.cmd_cnt = 2;
	shell.infile = "test.c";
	shell.outfile = "out";

	char *argv1[] = {"cat", NULL};
	char *argv2[] = {"grep", "main", NULL};

	shell.cmds = malloc(sizeof(t_cmd) * 2);
	shell.cmds[0].argv = argv1;
	shell.cmds[1].argv = argv2;
	execution(&shell);
	return (0);
}

void	execution(t_shell *shell)
{
	int tmpin = dup(0);
	int tmpout = dup(1);

	int fdin;
	if (shell->infile) {
		fdin = open(shell->infile, O_RDONLY);
	} else {
		fdin = dup(tmpin);
	}

	pid_t	pid;
	int		fdout;
	uint32_t	i = 0;

	while (i < shell->cmd_cnt)
	{
		dup2(fdin, 0);
		close(fdin);

		if (i == shell->cmd_cnt - 1) {//last one
			if (shell->outfile) {
				fdout = open(shell->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
			} else {
				fdout = dup(tmpout);
			}
		}

		else {
			int fdpipe[2];
			pipe(fdpipe);
			fdin = fdpipe[0];
			fdout = fdpipe[1];
		}

		dup2(fdout, 1);
		close(fdout);

		pid = fork();

		if (pid == 0) {
			ft_execvp(shell->cmds[i].argv[0], shell->cmds[i].argv);
			perror("execvp: ");
			exit(1);
		}

		i++;
	}

	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);

	waitpid(pid, NULL, 0);
}
