/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 21:20:00 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q minishell");
}

void	free_all(t_data *data)
{
	size_t i;

	i = 0;
	// free_env_lst(data->env_lst);//いらなそう
	free_lex_lst(data->lex_lst);
	while (data->input[i])
	{
		if (data->input[i] != NULL)
			free(data->input[i]);
		i++;
	}
	if (data->input != NULL)
		free(data->input);
}

int main(int argc, char *argv[], char **envp)
{
	t_data	data;

	data.envp = envp;
	store_env_lst(&data, envp);
	while (1)
	{
		signal(SIGINT, SIG_IGN); // Ctl +C
		signal(SIGQUIT, SIG_IGN);//??
		user_input(&data);//入力受取
		lexer(&data, data.input); //字句解析
		// creat_abstract_syntax(&data) //抽象構文木の生成
		//変数展開
		//コマンド実行
		free_all(&data);
	}
	return (0);
}
