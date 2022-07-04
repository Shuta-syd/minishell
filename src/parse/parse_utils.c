/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:07:33 by shogura           #+#    #+#             */
/*   Updated: 2022/07/04 21:47:15 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_meta_char(t_token **lex_lst, char *meta_char)
{
	if (ft_strcmp((*lex_lst)->token, meta_char) == 0)
	{
		*lex_lst = (*lex_lst)->next;
		return (true);
	}
	return (false);
}
