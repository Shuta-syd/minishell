/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:34:47 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 18:19:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		sub = (char *)malloc(sizeof(char) * 1);
	else
	{
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
		sub = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start] && start < s_len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
