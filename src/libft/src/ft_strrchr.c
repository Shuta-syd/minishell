/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:01:09 by shogura           #+#    #+#             */
/*   Updated: 2022/04/14 20:56:52 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	charset;
	char	*tmp;

	tmp = NULL;
	charset = (char)c;
	while (*s)
	{
		if (*s == charset)
			tmp = (char *)s;
		s++;
	}
	if (tmp)
		return ((char *)tmp);
	else if (c == 0)
		return ((char *)s);
	return (NULL);
}
