/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:36:35 by shogura           #+#    #+#             */
/*   Updated: 2022/07/24 15:17:09 by shogura          ###   ########.fr       */
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
