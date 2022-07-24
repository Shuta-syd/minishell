/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:36:35 by shogura           #+#    #+#             */
/*   Updated: 2022/07/24 12:08:13 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*extract_sign(char *input)
{
	char	*sign;
	char	*start;
	char	*ret;

	sign = ft_strstr(input, "<<") + 2;
	while (*sign == ' ')
		sign++;
	start = sign;
	while (*sign != ' ' && *sign != '\0')
		sign++;
	ret = ft_substr(start, 0, sign - start);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

size_t	count_input_len(t_list *heredoc, char *input)
{
	size_t	i;
	size_t	total_len;

	i = 0;
	total_len = ft_strlen(input);
	input = ft_strstr(input, "<<");
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '\0')
			break;
		i++;
		total_len--;
	}
	while (heredoc)
	{
		total_len += ft_strlen((char *)heredoc->content);
		heredoc = heredoc->next;
	}
	return (total_len);
}
