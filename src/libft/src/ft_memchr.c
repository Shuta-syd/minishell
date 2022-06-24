/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:04:38 by shogura           #+#    #+#             */
/*   Updated: 2022/04/09 17:32:12 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	charset;

	str = (unsigned char *)s;
	charset = (unsigned char)c;
	while (n-- > 0)
	{
		if (*str == charset)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
