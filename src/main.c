/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/07/26 20:14:51 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q minishell");
// }

static void	core(t_shell *shell);

int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;
	char	ch;

	motd();
	g_status = 0;
	signal(SIGINT, &handle_signal);
	signal(SIGQUIT, SIG_IGN);
	store_env_lst(&shell, envp);
	while (1)
	{
		shell = (t_shell){};
		shell.input = readline(PROMPT);
		if (shell.input == NULL)
			exit_("\b\bexit", EXIT_SUCCESS);
		if (shell.input[0] != '\0')
			core(&shell);
		else
			free(shell.input);
	}
	return (0);
}

static void	core(t_shell *shell)
{
	add_history(shell->input);
	heredoc(shell);
	lexer(shell);
	executor(shell);
	reset(shell);
}
