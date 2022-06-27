/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:52:00 by shogura           #+#    #+#             */
/*   Updated: 2022/06/27 15:46:32 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	search_path_from_env(t_data *data)
{
	t_env	*env_lst;
	bool	is_path;
	char	*path_val;

	env_lst = data->env_lst;
	while (env_lst)
	{
		is_path = ft_strstr(env_lst->val, "PATH");
		if (is_path)
		{
			path_val = env_lst->val;
			return;
		}
		env_lst = env_lst->next;
	}
}

void	free_env_lst(t_env *env_lst)
{
	t_env	*tmp;

	while (env_lst)
	{
		tmp = env_lst;
		env_lst = env_lst->next;
		free(tmp);
	}
}

t_env	*get_env_last_node(t_env *env_lst)
{
	t_env	*last_node;
	t_env	*inherit_lst;

	inherit_lst = env_lst;
	if (env_lst == NULL)
		return (NULL);
	while (inherit_lst)
	{
		last_node = inherit_lst;
		inherit_lst = inherit_lst->next;
		if (inherit_lst == NULL)
			break ;
	}
	return (last_node);
}

void	env_node_add_back(t_env **env_lst, t_env *new_node)
{
	t_env	*last_node;

	if (env_lst == NULL || new_node == NULL)
		return ;
	else if (*env_lst == NULL)
	{
		*env_lst = new_node;
		return ;
	}
	last_node = get_env_last_node(*env_lst);
	last_node->next = new_node;
}

t_env	*env_node_new(char *env)
{
	t_env	*new_env_node;

	new_env_node = ft_calloc(1, sizeof(t_env));
	if (new_env_node == NULL)
		return (NULL);
	new_env_node->val = env;
	new_env_node->next = NULL;
	return (new_env_node);
}

//環境変数のリスト構造化
void	store_env_lst(t_data *data, char **envp)
{
	t_env	*new_node;
	size_t	i;

	i = 1;
	data->env_lst = env_node_new(envp[0]);
	if (data->env_lst == NULL)
		return; // error
	while (envp[i])
	{
		new_node = env_node_new(envp[i]);
		if (new_node == NULL)
			return; // error
		env_node_add_back(&data->env_lst, new_node);
		i++;
	}
	search_path_from_env(data);
}
