/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:40:33 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 22:40:44 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_lex_lst(t_token *lex_lst)
{
	t_token *tmp;

	tmp = lex_lst;
	while (tmp)
	{
		printf("type > %d ", tmp->type);
		printf("token > %s%s%s\n", GREEN, tmp->token, C_DEFAULT);
		tmp = tmp->next;
	}
}

void	free_lex_lst(t_data *data)
{
	t_token	*tmp;

	if (data->lex_lst == NULL)
		return ;
	while (data->lex_lst)
	{
		tmp = data->lex_lst;
		if (data->lex_lst->token != NULL)
			free(data->lex_lst->token);
		data->lex_lst = data->lex_lst->next;
		if (tmp != NULL)
			free(tmp);
	}
	free(data->lex_lst);
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

void	store_lex_lst(t_data *data, char **input)
{
	t_token	*node;
	char	*word;

	if (**input == '\0')
		return;
	word = fetch_word(input);
	if (word == NULL)
		return;
	node = lex_node_new(word, NOTYPE);
	lex_node_add_back(&data->lex_lst, node);
	free(word);
	word = NULL;
	store_lex_lst(data, input);
}
