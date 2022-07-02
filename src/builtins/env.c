/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:08:02 by shogura           #+#    #+#             */
/*   Updated: 2022/06/30 19:36:32 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env(t_data *data)
{
	int i;
	t_env	*env_lst;

	i = 0;
	env_lst = data->env_lst;
	while (env_lst)
	{
		printf("%s=%s\n", env_lst->key, env_lst->val);
		env_lst = env_lst->next;
	}
}
