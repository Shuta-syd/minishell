/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:26:31 by shogura           #+#    #+#             */
/*   Updated: 2022/04/06 22:31:42 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;
	unsigned char	stopper;
	size_t			i;

	i = 0;
	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	stopper = (unsigned char)c;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
	{
		dst_cp[i] = src_cp[i];
		if (dst_cp[i] == stopper)
			return ((void *)dst + i + 1);
		i++;
	}
	return (NULL);
}
