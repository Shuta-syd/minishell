/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/29 19:32:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*extract_sign(char *input)
{
	char	*sign;
	char	*start;
	char	*ret;

	sign = ft_strstr(input, "<<") + 2;
	while (*sign && *sign == ' ')
		sign++;
	start = sign;
	while (ft_strchr(" <>\0", *sign) == 0)
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
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR, 0644);
	if (fd < 0)
		return ;
	while (heredoc_lst)
	{
		line = (char *)heredoc_lst->content;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
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
		heredoc_input = readline("> ");
		if (heredoc_input == NULL)
			return ;
		if (ft_strcmp(sign, heredoc_input) == 0)
		{
			free(heredoc_input);
			free(sign);
			return;
		}
		ret = expand_env(heredoc_input, data, true);
		node = ft_lstnew(ret);
		free(heredoc_input);
		ft_lstadd_back(heredoc_lst, node);
	}
}

void	heredoc(t_shell *data)
{
	t_list	*heredoc_lst;

	heredoc_lst = NULL;
	if (ft_strstr(data->input, "<<") == NULL)
		return ;
	loop_heredoc(data->input, &heredoc_lst, data);
	write_heredoc_file(heredoc_lst);
	ft_lstclear(&heredoc_lst, free);
}
