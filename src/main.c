/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/26 13:49:16 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

///*
__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q minishell");
}
//*/

void	free_all(t_data *data)
{
	size_t i;

	i = 0;
	free_env_lst(data->env_lst);
	free_lex_lst(data->lex_lst);
	while (data->input[i])
	{
		free(data->input[i]);
		i++;
	}
	free(data->input);
}

//envp → envコマンド結果を格納
int main(int argc, char *argv[], char **envp)
{
	t_data	data;

	store_env_lst(&data, envp);
	while (1)
	{
		user_input(&data);//入力受取
		lexer(&data, data.input); //字句解析
		// creat_abstract_syntax(&data) //抽象構文木の生成
		//変数展開
		//コマンド実行
		free_all(&data);
	}
	return 0;
}
