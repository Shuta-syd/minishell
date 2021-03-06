/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:42:59 by shogura           #+#    #+#             */
/*   Updated: 2022/07/27 18:56:19 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_status = 130;
	}
	else if (signal == SIGQUIT)
	{
		ft_putstr("Quit: ");
		ft_putnbr(SIGQUIT);
		ft_putchar('\n');
	}
}
