/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:11:07 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/15 19:55:54 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int main(void)
{
	t_shell	shell;
	shell = (t_shell){};
	shell.cmd_cnt = 3;
	shell.infile = NULL;
	shell.outfile = NULL;
	shell.outfile_mode = 0;

	char *argv1[] = {"cat", "test.c", NULL};
	char *argv2[] = {"grep", "all", NULL};
	char *argv3[] = {"wc", NULL};

	shell.cmds = malloc(sizeof(t_cmd) * shell.cmd_cnt);
	shell.cmds[0].argv = argv1;
	shell.cmds[1].argv = argv2;
	shell.cmds[2].argv = argv3;
	executor(&shell);
	return (0);
}
