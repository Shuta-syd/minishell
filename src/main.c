/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/07/15 14:42:07 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q minishell");
}

int main(int argc, char *argv[], char **envp)
{
	t_shell	shell;

	shell = (t_shell){};
	signal(SIGINT, &handle_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		shell.input = readline(PROMPT);
		if (shell.input == NULL)
			exit_("\b\bexit", EXIT_SUCCESS);
		printf("%s\n", shell.input);
		free(shell.input);
	}
	return (0);
}
