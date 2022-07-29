/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:38:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/29 19:17:58 by tharaguc         ###   ########.fr       */
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

static char	*get_key(char *arg)
{
	size_t	i;
	char	*res;

	i = 0;
	while (arg[i] != '=')
		i++;
	res = ft_calloc(i, sizeof(char));
	if (res == NULL)
		return (NULL);
	return (ft_strncpy(res, arg, i));
}

int	ft_export(t_shell *shell, char *arg)
{
	t_env	*new;
	char	*key;

	if (validate(arg) == false)
	{
		ft_putendl("not a valid identifier");
		return (1);
	}
	key = get_key(arg);
	ft_unset(shell, key);
	free(key);
	new = env_node_new(arg);
	env_node_add_back(&shell->env_lst, new);
	return (0);
}
