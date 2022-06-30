/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:40:08 by tharaguc          #+#    #+#             */
/*   Updated: 2022/06/30 18:47:34 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ms_getenv(t_data *data, char *name)
{
	t_env *tmp;

	tmp = data->env_lst;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, name, ft_strlen(name)) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
}
