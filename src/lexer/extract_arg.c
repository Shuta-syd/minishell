/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:39:28 by shogura           #+#    #+#             */
/*   Updated: 2022/07/21 19:19:47 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Stores the argument enclosed in quote, also expands environment variables.
*/
char	*store_quoted_arg(t_shell *data, char *input, size_t *i, char quote)
{
	size_t	len;
	char	*arg;

	len = 0;
	*i += 1;
	while (input[*i] != quote)
	{
		(*i)++;
		len++;
	}
	if (quote == '\"')
		arg = expand_env(&input[*i - len], data, true);
	else
		arg = ft_substr(input, *i - len, len);
	if (arg == NULL)
		return (NULL);
	return (arg);
}

/*
	Extract arg and remove excess space
*/
char	*extract_arg(t_shell *data, char *input, char **start, size_t *i)
{
	char	*arg;
	char	*ret;

	ret = NULL;
	if (**start == '$')
		arg = expand_env(*start, data, false);
	else if (input[*i + 1] == '\0')
		arg = ft_substr(input, *start - input, &input[*i] - *start + 1);
	else
		arg = ft_substr(input, *start - input, &input[*i] - *start);
	if (arg == NULL)
		exit(1);
	ret = ft_strtrim(arg, " ");
	if (ret == NULL)
		exit(1);
	free(arg);
	if (*ret == '$')
	{
		arg = expand_env(ret, data, false);
		free(ret);
		ret = arg;
	}
	*start = input + *i + 1;
	return (ret);
}
