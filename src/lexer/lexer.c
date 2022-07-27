/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:01 by shogura           #+#    #+#             */
/*   Updated: 2022/07/27 15:44:39 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exit_session(t_shell *data, int status, char *msg)
{
	(void)data;
	g_status = status;
	exit_(msg, ft_itoa(g_status));
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
		if ((input[i] == ' ' && input[i - 1] != ' ')
			|| input[i + 1] == '$' || input[i + 1] == '\0')
			cmds->args[j++] = extract_arg(data, input, &start, &i);
		else if (ft_strchr("<>", input[i])
			&& (input[i] != '<' && input[i] != '<'))
			cmds->args[j++] = extract_arg(data, input, &start, &i);
		else if (input[i] == '\"' || input[i] == '\'')
		{
			cmds->args[j++] = store_quoted_arg(data, input, &i, input[i]);
			start = input + i++;
		}
		if (ft_strchr("<>", input[i]))
			break ;
		i++;
	}
	cmds->args[j] = NULL;
}

/*
	Set up in a format that is easy to execve
*/
void	formatting_to_exe(t_shell *data, t_cmd *cmds, char *input)
{
	size_t	arg_cnt;
	char	*input_trimmed;

	input_trimmed = ft_strtrim(input, " ");
	if (input_trimmed == NULL)
		exit_session(data, 1, "Memory error\nexit");
	arg_cnt = count_args(input_trimmed);
	cmds->args = ft_calloc(arg_cnt, sizeof(char *));
	if (cmds->args == NULL)
		exit_session(data, 1, "Memory error\nexit");
	store_args(data, cmds, input_trimmed);
	free(input_trimmed);
}

int	lexer(t_shell *data)
{
	size_t	i;
	char	**input;

	i = 0;
	if (arg_is_quoted(data) == false)
		return (1);
	data->exe = ft_calloc(1, sizeof(t_exe));
	if (data->exe == NULL)
		exit_session(data, 1, "Memory error\nexit");
	store_redirect_in_out(data, data->input);
	data->exe->cmd_cnt = count_cmds(data->input);
	input = split_by_pipe(data, data->input, data->exe->cmd_cnt);
	if (input == NULL)
		exit_session(data, 1, "Memory error\nexit");
	data->exe->cmds = ft_calloc(data->exe->cmd_cnt, sizeof(t_cmd));
	if (data->exe->cmds == NULL)
		exit_session(data, 1, "Memory error\nexit");
	while (input[i])
	{
		formatting_to_exe(data, &data->exe->cmds[i], input[i]);
		free(input[i]);
		i++;
	}
	free(input);
	return (0);
}
