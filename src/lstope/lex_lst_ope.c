/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_lst_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:40:33 by shogura           #+#    #+#             */
/*   Updated: 2022/06/29 18:41:40 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_lex_lst(t_token *lex_lst)
{
	while (lex_lst)
	{
		printf("type->%d token->%s\n", lex_lst->type, lex_lst->token);
		lex_lst = lex_lst->next;
	}
}

void	free_lex_lst(t_token *lex_lst)
{
	t_token	*tmp;

	if (lex_lst == NULL)
		return ;
	while (lex_lst)
	{
		tmp = lex_lst;
		if (lex_lst->token != NULL)
			free(lex_lst->token);
		lex_lst = lex_lst->next;
		if (tmp != NULL)
			free(tmp);
	}
}

t_token	*get_lex_last_node(t_token *lex_lst)
{
	t_token	*last_node;
	t_token	*inherit_lst;

	inherit_lst = lex_lst;
	if (lex_lst == NULL)
		return (NULL);
	while (inherit_lst)
	{
		last_node = inherit_lst;
		inherit_lst = inherit_lst->next;
		if (inherit_lst == NULL)
			break;
	}
	return (last_node);
}

void	lex_node_add_back(t_token **lex_lst, t_token *new_node)
{
	t_token	*last_node;

	if (lex_lst == NULL || new_node == NULL)
		return;
	else if (*lex_lst == NULL)
	{
		*lex_lst = new_node;
		return;
	}
	last_node = get_lex_last_node(*lex_lst);
	last_node->next = new_node;
}

t_token	*lex_node_new(char *token, int type)
{
	t_token	*new_token_node;

	new_token_node = ft_calloc(1, sizeof(t_token));
	if (new_token_node == NULL)
		return (NULL);
	new_token_node->token = ft_strdup(token);
	if (new_token_node->token == NULL)
		return (NULL);
	new_token_node->type = type;
	new_token_node->next = NULL;
	return (new_token_node);
}

//入力値のリスト化
void	store_lex_lst(t_data *data, char **input)
{
	size_t	i;
	t_token	*new_node;

	i = 1;
	data->lex_lst = NULL;
	if (input[0] == NULL) // enter || space だけの時
		return ;
	data->lex_lst = lex_node_new(input[0], NOTYPE);
	if (data->lex_lst == NULL)
		return; // error
	while (input[i])
	{
		new_node = lex_node_new(input[i], NOTYPE);
		if (new_node == NULL)
			return; // error
		lex_node_add_back(&data->lex_lst, new_node);
		i++;
	}
	return ;
}
