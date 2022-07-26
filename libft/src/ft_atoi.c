/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:27:40 by shogura           #+#    #+#             */
/*   Updated: 2022/07/26 23:31:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(int minus)
{
	if (minus > 0)
		return ((int)LONG_MAX);
	return ((int)LONG_MIN);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				minus;
	long long		num;

	i = 0;
	num = 0;
	minus = 1;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus = -1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		num = 10 * num + (str[i] - '0');
		if (num > LONG_MAX / 10 || (num == (LONG_MAX / 10)
				&& str[i] - '0' > (LONG_MAX % 10)))
			return (ft_overflow(minus));
		i++;
	}
	return ((int)num * minus);
}
