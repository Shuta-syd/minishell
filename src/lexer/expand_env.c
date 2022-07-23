/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:37:50 by shogura           #+#    #+#             */
/*   Updated: 2022/07/23 20:09:58 by shogura          ###   ########.fr       */
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
			while (ft_strchr("<>$\" \0", arg[i]) == NULL)
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

	key_tmp = *key;
	while (key_tmp)
	{
		content = ms_getenv(data, (char *)key_tmp->content);
		node = ft_lstnew(content);
		ft_lstadd_back(val, node);
		key_tmp = key_tmp->next;
	}
}

char	*extract_env_val(char *arg, t_shell *data)
{
	char	*key;
	char	*root;
	char	*val;
	size_t	len;

	len = -1;
	while (*arg)
	{
		if (*arg == '$')
		{
			root = arg + 1;
			while (*arg != ' ' && *arg)
			{
				arg++;
				len++;
			}
			break ;
		}
		arg++;
	}
	key = ft_substr(root, 0, len);
	if (key == NULL)
		return (NULL);
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
	ret = create_expanded_arg(arg, &env_val, len);
	ft_lstclear(&env_key, free);
	ft_lstclear(&env_val, free);
	if (ret == NULL)
		exit(1);
	return (ret);
}
