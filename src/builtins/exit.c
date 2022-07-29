/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:37:39 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/28 13:52:22 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_(char *msg, char *s)
{
	int	status;

	status = 0;
	if (s != NULL)
		status = ft_atoi(s);
	while (s != NULL && *s)
	{
		if (ft_isdigit(*s) == 0)
		{
			status = 255;
			break ;
		}
		s++;
	}
	ft_putendl(msg);
	g_status = status;
	exit(status);
}
