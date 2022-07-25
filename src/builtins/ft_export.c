/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:38:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/25 18:26:11 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	validate(char *arg)
{
	if (ft_strchr(arg, '=') == NULL)
		return (false);
	while (*arg != '=')
	{
		if (*arg == ' ')
			return (false);
		arg++;
	}
	return (true);
}

int	ft_export(t_shell *shell, char *arg)
{
	t_env	*new;

	if (validate(arg) == false)
	{
		ft_putendl("not a valid identifier");
		return (1);
	}
	new = env_node_new(arg);
	env_node_add_back(&shell->env_lst, new);
	return (0);
}
