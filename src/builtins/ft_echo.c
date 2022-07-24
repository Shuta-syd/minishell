/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:29:51 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/24 17:49:05 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_flag(int argc, char **argv);

int	ft_echo(char **argv)
{
	int	i;
	int	flag;
	int	argc;

	argc = 1;
	while (argv[argc])
		argc++;
	ft_putendl("=This is builtin echo=");
	flag = check_flag(argc, argv);
	i = flag;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (i != argc - 1)
			write(1, " ", 1);
		i++;
	}
	if (flag != 2)
		write(1, "\n", 1);
	return (0);
}

static int	check_flag(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (ft_strcmp(argv[1], "-n") == 0)
		return (2);
	return (1);
}
