/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:42:59 by shogura           #+#    #+#             */
/*   Updated: 2022/07/15 14:36:42 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_redisplay();
	}
}
