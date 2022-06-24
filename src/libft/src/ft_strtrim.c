/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:42:39 by shogura           #+#    #+#             */
/*   Updated: 2022/04/06 21:05:07 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static size_t	ft_wordcount(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	set_count;

	start = 0;
	end = ft_strlen(s1) - 1;
	set_count = 0;
	while (s1[start] && ft_checkset(s1[start++], set))
		set_count++;
	while (end >= 0 && ft_checkset(s1[end--], set))
		set_count++;
	if (set_count > ft_strlen(s1))
		return (set_count - ft_strlen(s1));
	return (ft_strlen(s1) - set_count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*new_s;
	size_t	len;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	len = ft_wordcount(s1, set);
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	if (len != 0)
	{
		while (*s1 && ft_checkset(*s1, set))
			s1++;
		while (*s1 && len-- > 0)
			new_s[i++] = *s1++;
	}
	new_s[i] = '\0';
	return (new_s);
}
