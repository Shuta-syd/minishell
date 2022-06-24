/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:44:11 by shogura           #+#    #+#             */
/*   Updated: 2022/04/13 18:38:19 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	if (dst == src || n == 0)
		return (dst);
	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	if (dst_cp < src_cp)
		return (ft_memcpy(dst, src, n));
	else
		while (n-- > 0)
			dst_cp[n] = src_cp[n];
	return (dst);
}
