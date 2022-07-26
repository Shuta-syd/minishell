/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/26 09:15:29 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*extract_sign(char *input)
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

void	write_heredoc_file(t_list *heredoc_lst)
{
	char	*line;
	int		fd;

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

void	loop_heredoc(char *input, t_list **heredoc_lst, t_shell *data)
{
	char	*sign;
	char	*heredoc_input;
	char	*ret;
	t_list	*node;

	sign = extract_sign(input);
	while (42)
	{
		write(0, "> ", 2);
		heredoc_input = get_next_line(0);
		if (heredoc_input == NULL)
			return ;//error
		if (ft_strncmp(sign, heredoc_input, ft_strlen(sign)) == 0)
		{
			free(heredoc_input);
			free(sign);
			break ;
		}
		ret = expand_env(heredoc_input, data, true);
		free(heredoc_input);
		node = ft_lstnew(ret);
		ft_lstadd_back(heredoc_lst, node);
	}
	return ;
}

void	heredoc(t_shell *data)
{
	char	*sign;
	t_list	*heredoc_lst;

	heredoc_lst = NULL;
	if (ft_strstr(data->input, "<<") == NULL)
		return ;
	loop_heredoc(data->input, &heredoc_lst, data);
	write_heredoc_file(heredoc_lst);
	ft_lstclear(&heredoc_lst, free);
}
