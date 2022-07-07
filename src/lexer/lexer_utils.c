/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:46:59 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 19:54:28 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *fetch_deli(char **input)
{
	char	*ret_word;

	if (**input == '\0')
		return (NULL);
	ret_word = ft_calloc(2, sizeof(char));
	if (ret_word == NULL)
		return (NULL);
	ret_word[0] = **input;
	ret_word[1] = '\0';
	(*input)++;
	return (ret_word);
}

// ""に囲まれてる空白の取り扱い
char	*fetch_word(char **input)
{
	size_t	end;
	char	*input_cp;
	char	*ret_word;

	if (ft_strchr(DELIMITERS, **input))
		return (fetch_deli(input));
	end = 0;
	input_cp = *input;
	while (**input)
	{
		// ""に囲まれてる空白の取り扱い
		if (ft_strchr(DELIMITERS, **input))
			break;
		(*input)++;
		end++;
	}
	// ""に囲まれてる空白の取り扱い
	while (**input == ' ')
		(*input)++;
	ret_word = ft_substr(input_cp, 0, end);
	if (ret_word == NULL)
		return (NULL);
	return (ret_word);
}
