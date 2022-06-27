/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:53:46 by shogura           #+#    #+#             */
/*   Updated: 2022/06/24 20:54:42 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;
	size_t	dstlen;

	i = 0;
	dstlen = 0;
	size = ft_strnlen(dst, dstsize);
	if (size == dstsize)
		return (ft_strlen(src) + dstsize);
	size = dstsize - (size + 1);
	dstlen = ft_strlen(dst);
	while (i < size && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}
