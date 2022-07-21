/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:49:55 by shogura           #+#    #+#             */
/*   Updated: 2022/07/21 12:35:38 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*extract_redirect_file(char *input)
{
	char	*ret_file;
	char	*root;

	ret_file = NULL;

	while (*input != ' ')
		input++;
	root = input;
	while (*input)
	{
		if (ft_strchr("| ", *input))
			break ;
		input++;
	}
	ret_file = ft_substr(root, 0, input - root);
	if (ret_file == NULL)
		return (NULL);
	return (ret_file);
}

/*
	Retrieve and store the infile and outfile of the redirect
*/
void	store_redirect_in_out(t_shell *data, char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (ft_strchr("<", input[i]))
			data->exe->infile = extract_redirect_file(&input[i + 1]);
		else if (ft_strchr(">", input[i]) && input[i + 1] != '>')
		{
			data->exe->outfile = extract_redirect_file(&input[i + 1]);
			data->exe->outfile_mode = TRUNC;
		}
		else if (ft_strchr(">", input[i]) && input[i + 1] != '>')
		{
			i++;
			data->exe->outfile = extract_redirect_file(&input[i]);
			data->exe->outfile_mode = APPEND;
		}
		i++;
	}
}
