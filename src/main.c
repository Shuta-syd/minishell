/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 18:25:55 by shogura          ###   ########.fr       */
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
static void	store_env_lst(t_env *lst, char **envp)
{
	t_env	*prev;
	t_env	*tmp;
	size_t	i;

	i = 1;
	lst->val = ft_strdup(envp[0]);
	if (lst->val == NULL)
		return ;//error
	while (envp[i])
	{
		tmp = ft_calloc(1, sizeof(t_env *));
		if (tmp == NULL)
			return ; //error
		tmp->val = ft_strdup(envp[i]);
		if (tmp->val == NULL)
			return ; //error
		tmp->next = NULL;
		if (i == 1)
			lst->next = tmp;
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

	store_env_lst(&data.env, envp);
	while (1)
	{
		user_input(&data);//入力受取
		lexer(&data.lex, data.input); //字句解析
		// creat_abstract_syntax(&data) //抽象構文木の生成
		//
		free(data.input);
	}
	return 0;
}
