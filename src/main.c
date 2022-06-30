/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/30 20:05:28 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

///*
__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q minishell");
}
// */


int main(int argc, char *argv[], char **envp)
{
	t_data	data;

	data = (t_data){};
	data.envp = envp;
	store_env_lst(&data, envp);
	set_signal();
	while (1)
	{
		user_input(&data);
		lexer(&data, data.input);
		//構文解析
		//変数展開
		//コマンド実行
		free_all(&data);
	}
	return (0);
}
