/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/24 15:22:11 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	write_heredoc_file(t_list *heredoc_lst)
{
	char	*line;
	int	fd;

	line = NULL;
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR);
	if (fd < 0)
		return ; //error
	while (heredoc_lst)
	{
		line = (char *)heredoc_lst->content;
		write(fd, line, ft_strlen(line));
		heredoc_lst = heredoc_lst->next;
	}
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
			free(sign);
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

	heredoc_lst = NULL;
	input = data->input;
	if (ft_strstr(data->input, "<<") == NULL)
		return ;
	loop_heredoc(input, &heredoc_lst);
	write_heredoc_file(heredoc_lst);
	free(input);
	ft_lstclear(&heredoc_lst, free);
}
