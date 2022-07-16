/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:01 by shogura           #+#    #+#             */
/*   Updated: 2022/07/16 17:30:30 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	skip single quotes or Double quotes,
*/
void	skip_quote(char *input, size_t *i, char quote)
{
	size_t	j;

	j = *i + 1;
	while (input[j])
	{
		if (input[j] == quote)
			break ;
		j++;
	}
	*i = j;
}

/*
	Count the number of command lines
*/
u_int32_t	count_cmds(char *input)
{
	uint32_t	cmd_cnt;
	size_t		i;

	i = 0;
	cmd_cnt = 1;
	while (input[i])
	{
		if (input[i] == '\"')
			skip_quote(input, &i, '\"');
		else if (input[i] == '\'')
			skip_quote(input, &i, '\'');
		else if (input[i] == '|')
		{
			cmd_cnt++;
			i++;
		}
		i++;
	}
	return (cmd_cnt);
}

/*
	Split per pipe and extract command line (ignore pipes in double and single quarts)
*/
char	**split_by_pipe(char *input, uint32_t cmd_cnt)
{
	size_t		i_ret;
	size_t		j;
	char		**ret;
	char		*start;

	j = 0;
	i_ret = 0;
	start = input;
	ret = ft_calloc(cmd_cnt + 1, sizeof(char *));
	if (ret == NULL)
		exit(1);
	while (input[j])
	{
		if (input[j] == '\"' || input[j] == '\'')
			skip_quote(input, &j, input[j]);
		else if (input[j] == '|')
		{
			ret[i_ret++] = ft_substr(input, start - input, &input[j] - start);
			start += j + 1;
		}
		else if (input[j + 1] == '\0')
			ret[i_ret++] = ft_substr(input, start - input, &input[j] - start + 1);
		j++;
	}
	ret[i_ret] = NULL;
	return (ret);
}

/*
	Count the number of arguments when divided into each argument
*/
size_t	count_args(char *input)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 1;
	while (input[i])
	{
		if (input[i])
		{
			if (input[i] == ' ' && input[i + 1] != ' ')
				cnt++;
			else if (input[i + 1] == '\0')
				cnt++;
			else if (input[i] == '\"' || input[i] == '\'')
			{
				cnt++;
				skip_quote(input, &i, input[i]);
			}
			else if (ft_strchr("<>", input[i]))
				return (cnt);
			i++;
		}
	}
	return (cnt);
}

/*
	Extracts only the names of environment variables from the argument in a list
*/
void	extract_env_key(char *arg, t_list *env_key)
{
	size_t	len;
	size_t	i;
	char	*key;
	t_list	*node;

	i = 0;
	while (arg[i])
	{
		len = -1;
		if (arg[i] == '$')
		{
			while (arg[i++])
			{
				if (ft_strchr("<>$ ", arg[len]))
					break ;
				len++;
			}
			key = ft_substr(arg, i, len);
			node = ft_lstnew(key);
			ft_lstadd_back(&env_key, node);
		}
		else
			i++;
	}
}

/*
	Expand environment variable name to value
*/
void	get_env_val(t_shell *data, t_list *val, t_list *key)
{
	t_list	*node;
	t_list	*key_tmp;

	key_tmp = key;
	while (key_tmp)
	{
		node = ft_lstnew(ms_getenv(data, (char *)key_tmp->content));
		ft_lstadd_back(&val, node);
		key_tmp = key_tmp->next;
	}
}

/*
	Count the total number of characters by expanding the environment variable name to value
*/
size_t	count_arg_len(char *arg, t_list *val, t_list *key)
{
	size_t	len;
	t_list	*key_tmp;
	t_list	*val_tmp;

	key_tmp = key;
	val_tmp = val;
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
	Create environment variable expanded argument
*/
char	*create_expanded_arg(char *arg, t_list *val, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			
		}
		ret[j] = arg[i];
	}
}

/*
	Expand environment variables and create new strings
*/
char *expand_env(char *arg, t_shell *data)
{
	size_t	i;
	size_t	len;
	t_list	env_val;
	t_list	env_key;
	char	*ret;

	i = 0;
	extract_env_key(arg, &env_key);
	get_env_val(data, &env_val, &env_key);
	len = count_arg_len(arg, &env_val, &env_key);
	ret = create_expanded_arg(arg, &env_val, len);
}

/*
	Stores the argument enclosed in quote, also expands environment variables.
*/
char *store_quoted_arg(t_shell *data, char *input, char quote)
{
	size_t	len;
	char	*arg;

	len = 1;
	while (input[len] != quote)
		len++;
	arg = ft_substr(input, 1, len - 1);
	if (arg == NULL)
		exit(1);
	if (quote == '\"')
	{
		expand_env(arg, data);
	}
}

/*
	Store each character separated by a delimiter such as space, double quote, etc.
*/
void	store_args(t_shell *data, t_cmd *cmds, char *input)
{
	size_t	i;
	size_t	j;
	char	*start;

	i = 0;
	j = 0;
	start = input;
	while (input[i])
	{
		if (input[i] == ' ' && input[i - 1] != ' ')
		{
			cmds->args[j] = ft_substr(input, start - input, &input[i] - start);
			start += i + 1;
		}
		else if (input[j] == '\"' || input[j] == '\'')
		{
			cmds->args[j++] = store_quoted_arg(data, &input[i], input[j]);
			start += i + 1;
		}
		i++;
	}
}

/*
	Set up in a format that is easy to execve
*/
void formatting_to_exe(t_shell *data, t_cmd *cmds, char *input)
{
	size_t	i;
	size_t	arg_cnt;
	char	*input_trimmed;

	i = 0;
	input_trimmed = ft_strtrim(input, " ");
	if (input_trimmed == NULL)
		exit(1);
	arg_cnt = count_args(input_trimmed);
	cmds->args = ft_calloc(arg_cnt, sizeof(char *));
	if (cmds->args == NULL)
		exit(1);
	store_args(data, cmds, input_trimmed);
}

void lexer(t_shell *data)
{
	size_t	i;
	char **input;

	i = 0;
	data->exe = ft_calloc(1, sizeof(t_exe));
	if (data->exe == NULL)
		exit(1);
	data->exe->cmd_cnt = count_cmds(data->input);
	printf("cmd_cnt _> %u\n", data->exe->cmd_cnt);
	input = split_by_pipe(data->input, data->exe->cmd_cnt);
	if (input == NULL)
		exit(1);
	while (input[i])
		printf("%s\n", input[i++]);
	i = 0;
	data->exe->cmds = ft_calloc(data->exe->cmd_cnt, sizeof(t_cmd));
	if (data->exe->cmds == NULL)
		exit(1);
	while (input[i])
	{
		formatting_to_exe(data, &data->exe->cmds[i], input[i]);
		i++;
	}
	return ;
}
