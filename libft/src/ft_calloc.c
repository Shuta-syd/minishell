/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:30:50 by shogura           #+#    #+#             */
/*   Updated: 2022/05/06 16:13:18 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	malloc_size;
	void	*mem;

	if (size != 0 && SIZE_MAX / size < count)
		return (NULL);
	malloc_size = count * size;
	if (malloc_size == 0)
		malloc_size = 1;
	mem = (void *)malloc(malloc_size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, malloc_size);
	return (mem);
}
