/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/26 01:54:41 by shogura          ###   ########.fr       */
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
	t_env *tmp_env;
	t_token *tmp_token;

	i = 0;
	while (data->env_lst)
	{
		tmp_env = data->env_lst;
		free(tmp_env->val);
		data->env_lst = data->env_lst->next;
		free(tmp_env);
	}
	while (data->lex_lst)
	{
		tmp_token = data->lex_lst;
		free(tmp_token->token);
		data->lex_lst = data->lex_lst->next;
		free(tmp_token);
	}
	while (data->input[i])
	{
		free(data->input[i]);
		i++;
	}
	free(data->input);
}

//環境変数のリスト構造化
static void	store_env_lst(t_data *data, char **envp)
{
	t_env	*new_node;
	size_t	i;

	i = 1;
	data->env_lst = env_node_new(envp[0]);
	if (data->env_lst == NULL)
		return ; //error
	while (envp[i])
	{
		new_node = env_node_new(envp[i]);
		if (new_node == NULL)
			return ; //error
		env_node_add_back(&data->env_lst, new_node);
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
		lexer(&data, data.input); //字句解析
		// creat_abstract_syntax(&data) //抽象構文木の生成
		free_all(&data);
	}
	return 0;
}
