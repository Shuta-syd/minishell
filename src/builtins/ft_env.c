/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:09:45 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/24 18:13:29 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_shell *shell)
{
	t_env *list;

	list = shell->env_lst;
	while (list)
	{
		ft_putstr(list->key);
		ft_putstr("=");
		ft_putendl(list->val);
		list = list->next;
	}
}