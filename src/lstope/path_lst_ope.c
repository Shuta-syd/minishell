/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_lst_ope.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:56:04 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 16:05:14 by shogura          ###   ########.fr       */
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

//環境変数リストenv_lstからpathの部分を抽出したPATHリストを格納
void	store_path_lst(t_data *data)
{
	char	**path_val;
	int	i;

	i = 0;
	// path_val = ft_split(search_path_from_env(data->env_lst), ':');
	// while (path_val[i])
	// {
	// 	printf("%s\n", path_val[i]);
	// 	i++;
	// }
	// store_env_lst(data, path_val);

}
