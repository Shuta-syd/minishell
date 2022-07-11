/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:46:59 by shogura           #+#    #+#             */
/*   Updated: 2022/07/11 20:22:39 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	search_type(char *word)
{
	if (ft_strchr(word, '\"'))
		return (EXPANDABLE_QUOTED);
	else if (ft_strchr(word, '\''))
		return (NOT_EXPANDABLE);
	else if (ft_strcmp(word, " ")  == 0)
		return (TP_DELIMITER);
	else if (ft_strchr(word, '<') || ft_strchr(word, '>'))
		return (TP_REDIRECT);
	else if (ft_strcmp(word, "|") == 0)
		return (TP_PIPE);
	else
		return (TP_NORMAL);
}

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

char *fetch_rediret(char **input)
{
	char	*input_cp;
	char	*ret;
	size_t	len;

	len = 1;
	input_cp = *input;
	(*input)++;
	if (**input == '<' || **input == '>')
	{
		len++;
		(*input)++;
	}
	ret = ft_substr(input_cp, 0, len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char	*fetch_deli(char **input)
{
	char	*ret_word;

	if (**input == '\0')
		return (NULL);
	else if (**input == '\"' || **input == '\'')
		return (fetch_quoted_word(input));
	else if (**input == '>' || **input == '<')
		return (fetch_rediret(input));
	ret_word = ft_substr(*input, 0, 1);
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

	printf("input->%s\n", *input);
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
