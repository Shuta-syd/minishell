/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 16:32:15 by shogura          ###   ########.fr       */
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

//環境変数のリスト構造化
void	store_env_lst(t_data *data, char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		data->env.val = ft_calloc(ft_strlen(envp[i]), sizeof(char));
		data->env.val = ft_strdup(envp[i]);
		i++;
	}
}

//envp → envコマンド結果を格納
int main(int argc, char *argv[], char **envp)
{
	t_data	data;

	store_env_lst(&data, envp);
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
