/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:42:59 by shogura           #+#    #+#             */
/*   Updated: 2022/07/02 16:54:56 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ctrl_d(void)
{
	write(1, "\b\b", 2);
	exit_(0);
}

void	ctrl_c(int signal)
{
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_redisplay();
}

void	set_signal(void)
{
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}
