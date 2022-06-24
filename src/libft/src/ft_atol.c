/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:27:40 by shogura           #+#    #+#             */
/*   Updated: 2022/05/27 16:52:57 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_overflow(int minus)
{
	if (minus != -1)
		return ((long)LLONG_MAX);
	return ((long)LLONG_MIN);
}

long	ft_atol(const char *str)
{
	int			i;
	int			minus;
	long long	num;

	i = 0;
	num = 0;
	minus = 1;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = 10 * num + (str[i] - '0');
		if (num > LONG_MAX / 10 || (num == (LONG_MAX / 10)
				&& str[i] - '0' > (LONG_MAX % 10)))
			return (ft_overflow(minus));
		i++;
	}
	return ((long)(num * minus));
}
