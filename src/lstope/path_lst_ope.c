/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_lst_ope.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:56:04 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 17:08:33 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*search_path_from_env(t_env *env_lst)
{
	bool	is_path;
	char	*path_val;

	while (env_lst)
	{
		is_path = ft_strstr(env_lst->val, "PATH");
		if (is_path)
		{
			path_val = env_lst->val;
			return (path_val);
		}
		env_lst = env_lst->next;
	}
	return (NULL);
}

