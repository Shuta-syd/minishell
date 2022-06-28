/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:42:59 by shogura           #+#    #+#             */
/*   Updated: 2022/06/28 19:34:14 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ctrl_c(int signal)
{
	// ft_putstr_fd("\b\b  \b\b\n", 1);
	ft_putstr_fd("\033[15C", 1);
	ft_putstr_fd("\b\b  \b\b\n", 1);
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
}

void	signal_handeler(void)
{
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}
