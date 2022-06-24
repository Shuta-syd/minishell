/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:32:12 by shogura           #+#    #+#             */
/*   Updated: 2022/04/09 17:10:58 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_s == NULL)
		return (NULL);
	ft_bzero(new_s, ft_strlen(s) + 1);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
