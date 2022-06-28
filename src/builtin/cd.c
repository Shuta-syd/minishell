/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:06:27 by shogura           #+#    #+#             */
/*   Updated: 2022/06/28 12:40:51 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	go_home(void);

void	cd(t_data *data)
{
	const char *path = data->lex_lst->next->token; //定数にする必要ない
	if (path == NULL || ft_strcmp(path, "~") == 0)
		go_home();
	else if (chdir(path) != 0)
		ft_putendl(strerror(errno));
}

static void	go_home(void)
{
	if (chdir(getenv("HOME")) != 0)
		printf("Can't found $HOME\n");
}
