/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/07/24 15:27:39 by shogura          ###   ########.fr       */
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

void	print_env_lst(t_env *env_lst)
{
	while (env_lst)
	{
		printf("%s=%s\n", env_lst->key, env_lst->val);
		env_lst = env_lst->next;
	}
}

int main(int argc, char *argv[], char **envp)
{
	t_shell	data;
	char	ch;

	data = (t_shell){};
	signal(SIGINT, &handle_signal);
	signal(SIGQUIT, SIG_IGN);
	store_env_lst(&data, envp);
	while (1)
	{
		data.input = readline(PROMPT);
		if (data.input == NULL)
			exit_("\b\bexit", EXIT_SUCCESS);
		if (data.input[0] != '\0')
		{
			add_history(data.input);
			heredoc(&data);
			lexer(&data);
			executor(&data);
			reset(&data);
		} else {
			free(data.input);
		}
	}
	return (0);
}
