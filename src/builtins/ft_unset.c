/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:41 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/27 14:05:23 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_shell *shell, char *key)
{
	t_env	*env;
	t_env	*tmp;

	env = shell->env_lst;
	tmp = NULL;
	while (env)
	{
		if (ft_strcmp(env->next->key, key) == 0)
		{
			tmp = env->next;
			env->next = tmp->next;
			break ;
		}
		env = env->next;
	}
	free(tmp->key);
	free(tmp->val);
	free(tmp);
}
