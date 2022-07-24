/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/24 12:08:22 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *merge_heredoc_input(t_list *heredoc, char *input)
{
	char	*ret;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = count_input_len(heredoc, input);
	printf("len->%zu\n", len);
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (input[i] == '>' && input[i + 1] == '>')
		ret[j++] = input[i++];
	while (heredoc)
		copy_lst_content(&ret, &j, &heredoc);
	while (input[i + 1] != '\0' && input[i + 1] != '|')
		i++;
	while (input[i])
		ret[j++] = input[i++];
	return (ret);
}

void	loop_heredoc(char *input, t_list **heredoc_lst)
{
	char	*sign;
	char	*heredoc_input;
	t_list	*node;

	sign = extract_sign(input);
	while (42)
	{
		write(0, "> ", 2);
		heredoc_input = get_next_line(0);
		if (ft_strncmp(sign, heredoc_input, ft_strlen(sign)) == 0)
		{
			free(heredoc_input);
			break ;
		}
		node = ft_lstnew(heredoc_input);
		ft_lstadd_back(heredoc_lst, node);
	}
	return ;
}

void	heredoc(t_shell *data)
{
	char	*input;
	char	*sign;
	t_list	*heredoc_lst;

	heredoc_lst = NULL;
	input = data->input;
	if (ft_strstr(data->input, "<<") == NULL)
		return ;
	loop_heredoc(input, &heredoc_lst);
	data->input = merge_heredoc_input(heredoc_lst, input);
	free(input);
	ft_lstclear(&heredoc_lst, free);
}
