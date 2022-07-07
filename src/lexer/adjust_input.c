/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:21:25 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 20:37:33 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_delimiter_prev_next(char *input)
{
	size_t	i;
	char	prev;
	char	next;

	i = 0;
	if (input[i + 1] == '\0')
		return (false);
	prev = input[i];
	next = input[i + 2];
	if (ft_strchr(DELIMITERS, prev) == 0)
	{
		if (ft_strchr(DELIMITERS, next) == 0)
			return (false);
	}
	return (true);
}

// ""に囲まれてる空白も数えてしまう
size_t	count_len_deled_str(char *input)
{
	size_t	i;
	size_t	len;
	size_t	len_ws;

	i = 0;
	len_ws = 0;
	len = ft_strlen(input) + 1;
	while (input[i])
	{
		if (input[i] == ' ' && is_delimiter_prev_next(&input[i - 1]))
			len_ws++;
		i++;
	}
	return (len - len_ws);
}

char	*del_white_space(char *input)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ret;

	i = 0;
	j = 0;
	len = count_len_deled_str(input);
	ret = ft_calloc(len, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (input[j])
	{
		//" "で囲まれてる空白はコピーしないため要修正
		if (input[j] != ' ' || is_delimiter_prev_next(&input[j - 1]) == false)
		{
			ret[i] = input[j];
			i++;
		}
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
