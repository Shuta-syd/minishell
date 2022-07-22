/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:31:03 by shogura           #+#    #+#             */
/*   Updated: 2022/07/22 20:29:34 by shogura          ###   ########.fr       */
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
	printf("start->[%s]\n", start);
	while (*sign != ' ' && *sign != '\0')
		sign++;
	ret = ft_substr(start, 0, sign - start);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

void	start_heredoc(char *input)
{
	char	*sign;

	sign = extract_sign(input);//EOF
}

void	heredoc(t_shell *data)
{
	char	*input;

	input = data->input;
	if (ft_strstr(input, "<<"))
		start_heredoc(input);
}
