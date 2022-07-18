/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:01 by shogura           #+#    #+#             */
/*   Updated: 2022/07/18 19:18:07 by shogura          ###   ########.fr       */
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
		if (input[j] == '|')
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
			else if (ft_strchr("<>", input[i]))
				return (cnt);
			if (input[i] == '\"' || input[i] == '\'')
			{
				cnt++;
				skip_quote(input, &i, input[i]);
			}
			i++;
		}
	}
	return (cnt);
}

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
			start = i + 1;
			i += 1;
			while (ft_strchr("<>$\" \0", arg[i]) == NULL)
				i++;
			key = ft_substr(arg, start, i - start);
			node = ft_lstnew(key);
			ft_lstadd_back(env_key, node);
			free(key);
			key = NULL;
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

	key_tmp = *key;
	while (key_tmp)
	{
		node = ft_lstnew(ms_getenv(data, (char *)key_tmp->content));
		ft_lstadd_back(val, node);
		key_tmp = key_tmp->next;
	}
}

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
void copy_env_val(char **dst, size_t	*j, t_list **env_val)
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

/*
	Expand environment variables and create new strings
*/
char *expand_env(char *arg, t_shell *data)
{
	size_t	i;
	size_t	len;
	t_list	*env_val;
	t_list	*env_key;
	char	*ret;

	i = 0;
	env_val = NULL;
	env_key = NULL;
	extract_env_key(arg, &env_key);
	get_env_val(data, &env_val, &env_key);
	len = count_arg_len(arg, &env_val, &env_key);
	ret = create_expanded_arg(arg, &env_val, len);
	if (ret == NULL)
		exit(1);
	return (ret);
}

/*
	Stores the argument enclosed in quote, also expands environment variables.
*/
char *store_quoted_arg(t_shell *data, char *input, size_t *i, char quote)
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
		arg = expand_env(&input[*i - len], data);
	else
		arg = ft_substr(input, *i - len, len);
	printf("arg->%s\n", arg);
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
		arg = expand_env(*start, data);
	else if (input[*i + 1] == '\0')
		arg = ft_substr(input, *start - input, &input[*i] - *start + 1);
	else
		arg = ft_substr(input, *start - input, &input[*i] - *start);
	ret = ft_strtrim(arg, " ");
	free(arg);
	if (*ret == '$')
	{
		arg = expand_env(ret, data);
		free(ret);
		ret = arg;
	}
	*start = input + *i + 1;
	return (ret);
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
		if ((input[i] == ' ' && input[i - 1] != ' ') || input[i + 1] == '\0')
			cmds->args[j++] =  extract_arg(data, input, &start, &i);
		else if (input[i] == '\"' || input[i] == '\'')
		{
			cmds->args[j++] = store_quoted_arg(data, input, &i, input[i]);
			start = input + i + 1;
			i++;
		}
		i++;
	}
	cmds->args[j] = NULL;
}

/*
	Set up in a format that is easy to execve
*/
void formatting_to_exe(t_shell *data, t_cmd *cmds, char *input)
{
	size_t	i;
	size_t	arg_cnt;
	char	*input_trimmed;

	input_trimmed = ft_strtrim(input, " ");
	printf("trimmed_>[%s]\n", input_trimmed);
	if (input_trimmed == NULL)
		exit(1);
	arg_cnt = count_args(input_trimmed);
	printf("arg_cnt->%zu\n", arg_cnt);
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
	data->exe->cmds = ft_calloc(data->exe->cmd_cnt, sizeof(t_cmd));
	if (data->exe->cmds == NULL)
		exit(1);
	printf("input->%s\n", input[0]);
	while (input[i])
	{
		formatting_to_exe(data, &data->exe->cmds[i], input[i]);
		i++;
	}
	i = 0;
	size_t j = 0;
	while (data->exe->cmd_cnt--)
	{
		j = 0;
		while (data->exe->cmds[i].args[j])
			printf("cmds_>[%s]\n", data->exe->cmds[i].args[j++]);
		i++;
	}
	return;
}
