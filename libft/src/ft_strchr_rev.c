/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:58:52 by shogura           #+#    #+#             */
/*   Updated: 2022/04/14 20:52:27 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_rev(const char *s, int c)
{
	char	charset;

	charset = (char)c;
	while (*s)
	{
		if (*s != charset)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
