/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:01 by shogura           #+#    #+#             */
/*   Updated: 2022/07/16 14:34:47 by shogura          ###   ########.fr       */
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
	Expand environment variables and create new strings
*/
char *expand_env(char *arg, t_shell *data)
{
	size_t	i;
	size_t	j;
	t_list	env;
	char	*ret;

	i = 0;
	j = 0;
	



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
