/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:06:18 by tharaguc          #+#    #+#             */
/*   Updated: 2022/06/12 15:48:06 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**dp_malloc(const char *str, char c);

char	**ft_split(const char *str, char c)
{
	char		**res;
	size_t		i;
	const char	*start;

	i = 0;
	res = dp_malloc(str, c);
	if (res == NULL)
		return (NULL);
	while (*str == c)
		str++;
	while (*str)
	{
		start = str;
		while (*str != c && *str)
			str++;
		res[i] = malloc(sizeof(char) * (str - start + 1));
		if (res[i] == NULL)
			return (NULL);
		ft_strlcpy(res[i], start, str - start + 1);
		while (*str == c && *str)
			str++;
		i++;
	}
	res[i] = NULL;
	return (res);
}

static char	**dp_malloc(const char *str, char c)
{
	char		**res;
	size_t		cnt;

	cnt = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str != c && *str)
			str++;
		cnt++;
		while (*str == c && *str)
			str++;
	}
	res = malloc(sizeof(char *) * (cnt + 1));
	return (res);
}
