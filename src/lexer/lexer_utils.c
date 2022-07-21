/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:40:10 by shogura           #+#    #+#             */
/*   Updated: 2022/07/21 11:40:54 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
/*
	Free dynamic memory of t_exe
*/
void free_t_exe(t_shell *data)
{
	size_t i;
	size_t j;

	i = 0;
	while (data->exe->cmd_cnt--)
	{
		j = 0;
		while (data->exe->cmds[i].args[j])
		{
			free(data->exe->cmds[i].args[j]);
			j++;
		}
		free(data->exe->cmds[i].args);
		i++;
	}
	free(data->exe->infile);
	free(data->exe->outfile);
	free(data->exe->cmds);
	free(data->exe);
}

/*
	skip single quotes or Double quotes,
*/
void skip_quote(char *input, size_t *i, char quote)
{
	size_t j;

	j = *i + 1;
	while (input[j])
	{
		if (input[j] == quote)
			break;
		j++;
	}
	*i = j;
}

/*
	Count the number of command lines
*/
u_int32_t count_cmds(char *input)
{
	uint32_t cmd_cnt;
	size_t i;

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
char **split_by_pipe(char *input, uint32_t cmd_cnt)
{
	size_t i_ret;
	size_t j;
	char **ret;
	char *start;

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
size_t count_args(char *input)
{
	size_t i;
	size_t cnt;

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
