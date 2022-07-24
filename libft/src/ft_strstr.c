/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:42:22 by shogura           #+#    #+#             */
/*   Updated: 2022/07/23 23:28:22 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_check_len(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
		len++;
	}
	return (len);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == needle[0])
			len = ft_check_len(haystack, needle);
		if (len == ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
