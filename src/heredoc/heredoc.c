/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/23 21:22:11 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	count_input_len(t_list *heredoc, char *input)
{
	size_t	i;
	size_t	total_len;

	i = 0;
	total_len = count_input_len(heredoc, input);
	total_len = ft_strlen(input);
	input = ft_strstr(input, "<<");
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '\0')
			break;
		total_len--;
	}
	while (heredoc)
	{
		total_len += ft_strlen((char *)heredoc->content);
		heredoc = heredoc->next;
	}
	return (total_len);
}

void	merge_heredoc_input(t_list *heredoc, char *input)
{
	char	*ret;
	size_t	len;

	len = count_input_len(heredoc, input);
}

char *extract_sign(char *input)
{
	char	*sign;
	char	*start;
	char	*ret;

	sign = ft_strstr(input, "<<") + 2;
	while (*sign == ' ')
		sign++;
	start = sign;
	while (*sign != ' ' && *sign != '\0')
		sign++;
	ret = ft_substr(start, 0, sign - start);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

void	loop_heredoc(char *sign, t_list **heredoc_lst)
{
	char	*heredoc_input;
	t_list	*node;

	while (42)
	{
		write(0, "> ", 2);
		heredoc_input = get_next_line(0);
		if (ft_strncmp(sign, heredoc_input, ft_strlen(sign)))
		{
			free(heredoc_input);
			break;
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

	if (ft_strstr(input, "<<") == 0)
		return ;
	heredoc_lst = NULL;
	input = data->input;
	sign = extract_sign(input);
	loop_heredoc(sign, &heredoc_lst);
	// data->input = merge_heredoc_input(heredoc_lst, input);
	free(input);
	ft_lstclear(&heredoc_lst, free);
}
