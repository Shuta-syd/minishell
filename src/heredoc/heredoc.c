/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/23 21:39:03 by shogura          ###   ########.fr       */
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
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (input[i] == '>' && input[i + 1] == '>')
		ret[j++] = input[i++];
	while (heredoc)
		copy_lst_content(&ret, &j, &heredoc);
	

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
