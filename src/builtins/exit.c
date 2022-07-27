/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:37:39 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/27 14:23:22 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_(char *msg, char *s)
{
	int	status;

	status = 0;
	if (s != NULL)
		status = ft_atoi(s);
	ft_putendl(msg);
	g_status = status;
	exit(status);
}
