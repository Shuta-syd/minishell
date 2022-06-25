/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 15:50:19 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q minishell");
}
*/

//envp → envコマンド結果を格納
int main(int argc, char *argv[], char **envp)
{
	t_data	data;

	data.envp = envp;
	while (1)
	{
		user_input(&data);//入力受取
		//lexer(&data); //字句解析
		// creat_abstract_syntax(&data) //抽象構文木の生成
		//
		free(data.input);
	}
	return 0;
}
