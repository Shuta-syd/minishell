/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/06/25 18:25:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	store_token_lst(t_token *lst, char **input)
{
	t_token	*prev;
	t_token	*tmp;
	size_t	i;

	i = 1;
	lst->type = NOTYPE;
	lst->token = ft_strdup(input[0]);
	if (lst->token == NULL)
		return; // error
	while (input[i])
	{
		tmp = ft_calloc(1, sizeof(t_token));
		if (tmp == NULL)
			return; // error
		tmp->type = NOTYPE;
		tmp->token = ft_strdup(input[i]);
		if (tmp->token == NULL)
			return; // error
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

// 字句解析のための関数(リスト構造化)
void	lexer(t_token *lst, char **input)
{
	store_token_lst(lst, input);
}
