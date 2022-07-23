/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/23 20:24:21 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

void	start_heredoc(char *input, t_list **heredoc_lst)
{
	char	*sign;
	char	*heredoc_input;
	t_list	*node;

	sign = extract_sign(input);
	while (42)
	{
		write(0, "> ", 2);
		heredoc_input = get_next_line(0);
		if (ft_strncmp(sign, heredoc_input, ft_strlen(sign) + 1))
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
	t_list	*heredoc_lst;

	input = data->input;
	heredoc_lst = NULL;
	if (ft_strstr(input, "<<"))
		start_heredoc(input, &heredoc_lst);
	
}
