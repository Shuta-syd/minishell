/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:01 by shogura           #+#    #+#             */
/*   Updated: 2022/07/15 23:56:30 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	through_quote(char *input, size_t *i, char quote)
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

u_int32_t	count_cmds(char *input)
{
	uint32_t	cmd_cnt;
	size_t		i;

	i = 0;
	cmd_cnt = 1;
	while (input[i])
	{
		if (input[i] == '\"')
			through_quote(input, &i, '\"');
		else if (input[i] == '\'')
			through_quote(input, &i, '\'');
		else if (input[i] == '|')
		{
			cmd_cnt++;
			i++;
		}
		i++;
	}
	return (cmd_cnt);
}

void	formatting_to_exe(t_shell *data, char *input)
{

}

char **split_by_pipe(char *input, uint32_t cmd_cnt)
{
	size_t		i_ret;
	size_t		j;
	char		**ret;
	char		*start_input;

	j = 0;
	i_ret = 0;
	start_input = input;
	ret = ft_calloc(cmd_cnt + 1, sizeof(char *));
	if (ret == NULL)
		exit(1);
	while (input[j])
	{
		if (input[j] == '\"')
			through_quote(input, &j, '\"');
		else if (input[j] == '\'')
			through_quote(input, &j, '\'');
		else if (input[j] == '|')
		{
			ret[i_ret] = ft_substr(input, start_input - input, &input[j] - start_input);
			i_ret++;
			start_input = input + j + 1;
		}
		else if (input[j + 1] == '\0')
		{
			ret[i_ret] = ft_substr(input, start_input - input, &input[j] - start_input + 1);
			i_ret++;
		}
		j++;
	}
	ret[i_ret] = NULL;
	return (ret);
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
	// while (input[i])
	// {
	// 	formatting_to_exe(data, input[i]);
	// 	i++;
	// }
	return ;
}

/*
	cat < Makefile | grep all | wc -l
*/
