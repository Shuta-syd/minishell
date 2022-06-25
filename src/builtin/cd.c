/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:50:03 by tharaguc          #+#    #+#             */
/*   Updated: 2022/06/14 21:29:02 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	go_home(void);

void	cd(t_data *data)
{
	const char	*path = data->inputs[1];
	if (path == NULL || ft_strcmp(path, "~") == 0)
		go_home();
	else if (chdir(path) != 0)
		printf("%s\n", strerror(errno));
}

static void	go_home(void)
{
	if (chdir(getenv("HOME")) != 0)
		ft_putstr("can't found $HOME\n");
}
