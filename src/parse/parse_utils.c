/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:07:33 by shogura           #+#    #+#             */
/*   Updated: 2022/07/04 22:27:19 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_meta_char(t_token **lex_lst, char *meta_ch)
{
	while (*meta_ch)
	{
		if (ft_strchr((*lex_lst)->token, *meta_ch) == 0)
		{
			*lex_lst = (*lex_lst)->next;
			return (true);
		}
		meta_ch++;
	}
	return (false);
}
