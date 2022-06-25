/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_lst_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:40:33 by shogura           #+#    #+#             */
/*   Updated: 2022/06/26 01:50:32 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	t_token *new_token_node;

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
