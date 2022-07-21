/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:44:48 by shogura           #+#    #+#             */
/*   Updated: 2022/07/21 18:50:29 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Count the total number of characters by expanding the environment variable name to value
*/
size_t	count_arg_len(char *arg, t_list **val, t_list **key)
{
	size_t	len;
	t_list	*key_tmp;
	t_list	*val_tmp;

	key_tmp = *key;
	val_tmp = *val;
	len = ft_strlen(arg);
	while (key_tmp)
	{
		len -= ft_strlen((char *)key_tmp->content);
		key_tmp = key_tmp->next;
	}
	while (val_tmp)
	{
		len += ft_strlen((char *)val_tmp->content);
		val_tmp = val_tmp->next;
	}
	return (len);
}

/*
	Copying environment variables
*/
void	copy_env_val(char **dst, size_t *j, t_list **env_val)
{
	size_t	i;
	char	*val;

	i = 0;
	val = (char *)(*env_val)->content;
	*env_val = (*env_val)->next;
	while (val[i])
	{
		(*dst)[*j] = val[i];
		(*j)++;
		i++;
	}
}

/*
	Create environment variable expanded argument
*/
char	*create_expanded_arg(char *arg, t_list **val, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (arg[i] != '\"' && arg[i])
	{
		if (arg[i] == '$')
		{
			i += 1;
			copy_env_val(&ret, &j, val);
			while (arg[i])
			{
				if (ft_strchr("<>$\" ", arg[i]))
					break;
				i++;
			}
		}
		else
			ret[j++] = arg[i++];
	}
	ret[j] = '\0';
	return (ret);
}
