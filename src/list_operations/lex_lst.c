/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:40:33 by shogura           #+#    #+#             */
/*   Updated: 2022/06/30 18:16:59 by tharaguc         ###   ########.fr       */
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
		printf("token > ");
		color(tmp->token, GREEN);
		printf("\n");
		tmp = tmp->next;
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
		// if (lex_lst->token != NULL)
			free(lex_lst->token);
		lex_lst = lex_lst->next;
		// if (tmp != NULL)
			free(tmp);
	}
	free(lex_lst);
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
	size_t	i;
	t_token	*new_node;

	i = 1;
	if (input[0] == NULL)//enter | space だけの時
	{
		data->lex_lst = NULL;
		return ;
	}
	data->lex_lst = lex_node_new(input[0], NOTYPE);
	if (data->lex_lst == NULL)
		return;
	while (input[i])
	{
		new_node = lex_node_new(input[i], NOTYPE);
		if (new_node == NULL)
			return;
		lex_node_add_back(&data->lex_lst, new_node);
		i++;
	}
	return ;
}
