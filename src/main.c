/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/07/21 12:24:25 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q minishell");
}

void	print_data_exe(t_shell *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("infile ->[%s] outfile->[%s] mode->[%d]\n", data->exe->infile, data->exe->outfile, data->exe->outfile_mode);
	printf("cmd_cnt->%zu\n", data->exe->cmd_cnt);
	while (data->exe->cmd_cnt--)
	{
		j = 0;
		while (data->exe->cmds[i].args[j])
			printf("arg->[%s]\n", data->exe->cmds[i].args[j++]);
		i++;
	}
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
		print_data_exe(&data);
		executor(&data);
		free(data.input);
	}
	return (0);
}
