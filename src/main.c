/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 18:55:05 by shogura          ###   ########.fr       */
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
	while (data->env)
	{
		tmp_env = data->env;
		free(tmp_env->val);
		data->env = data->env->next;
		free(tmp_env);
	}
	while (data->lex)
	{
		tmp_token = data->lex;
		free(tmp_token->token);
		data->lex = data->lex->next;
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
	t_env	*prev;
	t_env	*tmp;
	size_t	i;

	i = 0;
	while (envp[i])
	{
		tmp = ft_calloc(1, sizeof(t_env));
		if (tmp == NULL)
			return ; //error
		tmp->val = ft_strdup(envp[i]);
		if (tmp->val == NULL)
			return ; //error
		tmp->next = NULL;
		if (i == 0)
			data->env = tmp;
		else
			prev->next = tmp;
		prev = tmp;
		tmp = tmp->next;
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
