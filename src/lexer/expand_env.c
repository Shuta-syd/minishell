/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:37:50 by shogura           #+#    #+#             */
/*   Updated: 2022/07/27 13:57:31 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
/*
	Extracts only the names of environment variables from the argument in a list
*/
void	extract_env_key(char *arg, t_list **env_key)
{
	size_t	start;
	size_t	i;
	char	*key;
	t_list	*node;

	i = 0;
	while (arg[i] != '\"' && arg[i])
	{
		if (arg[i] == '$')
		{
			i += 1;
			start = i;
			while (ft_strchr("<>$\"\n \0", arg[i]) == NULL)
				i++;
			key = ft_substr(arg, start, i - start);
			node = ft_lstnew(key);
			ft_lstadd_back(env_key, node);
		}
		else
			i++;
	}
}

/*
	Expand environment variable name to value
*/
void	get_env_val(t_shell *data, t_list **val, t_list **key)
{
	t_list	*node;
	t_list	*key_tmp;
	char	*content;
	char	*status;

	status = NULL;
	key_tmp = *key;
	while (key_tmp)
	{
		if (ft_strcmp((char *)key_tmp->content, "?"))
		{
			status = ft_itoa(g_status);
			content = ft_strdup(status);
			free(status);
		}
		else
			content = ms_getenv(data, (char *)key_tmp->content);
		node = ft_lstnew(content);
		ft_lstadd_back(val, node);
		key_tmp = key_tmp->next;
	}
}

char	*extract_env_val(char *arg, t_shell *data)
{
	char	*key;
	char	*val;
	size_t	i;

	i = 1;
	while (arg[i] && ft_strchr("<>$\"\n \0", arg[i]) == NULL)
		i++;
	key = ft_substr(arg + 1, 0, i - 1);
	if (key == NULL)
		exit_session(data, 1, "Memory error\nexit");
	if (ft_strcmp(key, "?") == 0)
	{
		free(key);
		key = ft_itoa(g_status);
		val = ft_strdup(key);
	}
	else
		val = ft_strdup(ms_getenv(data, key));
	free(key);
	return (val);
}

/*
	Expand environment variables and create new strings
*/
char	*expand_env(char *arg, t_shell *data, bool quoted)
{
	size_t	len;
	t_list	*env_val;
	t_list	*env_key;
	char	*ret;

	if (quoted == false)
		return (extract_env_val(arg, data));
	env_val = NULL;
	env_key = NULL;
	extract_env_key(arg, &env_key);
	get_env_val(data, &env_val, &env_key);
	len = count_arg_len(arg, &env_val, &env_key);
	ret = create_expanded_arg(data, arg, &env_val, len);
	ft_lstclear(&env_key, free);
	ft_lstclear(&env_val, free);
	if (ret == NULL)
		exit_session(data, 1, "Memory error\nexit");
	return (ret);
}
