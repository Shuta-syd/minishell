/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:46:59 by shogura           #+#    #+#             */
/*   Updated: 2022/07/11 18:00:26 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*fetch_quoted_word(char **input)
{
	char		*input_cp;
	char		*ret;
	size_t	len;

	len = 2;
	input_cp = *input;
	(*input)++;
	while (**input && **input != '\"' && **input != '\'')
	{
		len++;
		(*input)++;
	}
	(*input)++;
	ret = ft_substr(input_cp, 0, len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char *fetch_deli(char **input)
{
	char	*ret_word;

	if (**input == '\0')
		return (NULL);
	else if (**input == '\"' || **input == '\'')
		return (fetch_quoted_word(input));
	ret_word = ft_calloc(2, sizeof(char));
	if (ret_word == NULL)
		return (NULL);
	ret_word[0] = **input;
	ret_word[1] = '\0';
	(*input)++;
	while (**input && **input == ' ')
		(*input)++;
	return (ret_word);
}

char	*fetch_word(char **input)
{
	size_t	len;
	char		*input_cp;
	char		*ret_word;

	if (ft_strchr(DELIMITERS, **input))
		return (fetch_deli(input));
	len = 0;
	input_cp = *input;
	while (**input)
	{
		if (ft_strchr(DELIMITERS, **input))
			break;
		(*input)++;
		len++;
	}
	ret_word = ft_substr(input_cp, 0, len);
	if (ret_word == NULL)
		return (NULL);
	return (ret_word);
}
