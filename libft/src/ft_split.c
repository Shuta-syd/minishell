/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:13:47 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 19:41:38 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr_rev(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	charset;

	str = (unsigned char *)s;
	charset = (unsigned char)c;
	while (*str)
	{
		if (*str != charset)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

static size_t	count_num_str(char const *s, char deli)
{
	size_t	num_str;

	num_str = 0;
	while (*s)
	{
		if (*s != deli)
		{
			num_str++;
			while (*s != deli && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (num_str);
}

static size_t	word_count(char const *src, char deli)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != deli)
		i++;
	return (i);
}

static char	**store_str(char **strs, char const *src, char deli)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*src)
	{
		src = ft_strchr_rev(src, deli);
		if (src == NULL)
			break ;
		len = word_count(src, deli);
		strs[i] = ft_calloc(len + 1, sizeof(char));
		if (strs[i] == NULL)
		{
			i = 0;
			while (strs[i])
				free(strs[i++]);
			free(strs);
			return (NULL);
		}
		ft_strlcpy(strs[i], src, len + 1);
		i++;
		src += len;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	num_str;

	if (s == NULL)
		return (NULL);
	num_str = count_num_str(s, c);
	strs = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (strs == NULL)
		return (NULL);
	return (store_str(strs, s, c));
}
