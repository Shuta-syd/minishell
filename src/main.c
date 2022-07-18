/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/07/18 11:50:00 by tharaguc         ###   ########.fr       */
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
	t_shell	data;

	data = (t_shell){};
	signal(SIGINT, &handle_signal);
	signal(SIGQUIT, SIG_IGN);
	store_env_lst(&data, envp);
	while (1)
	{
		data.input = readline(PROMPT);
		if (data.input == NULL)
			exit_("\b\bexit", EXIT_SUCCESS);
		lexer(&data);
		// printf("%s\n", data.input);
		executor(&data);
		free(data.input);
	}
	return (0);
}
