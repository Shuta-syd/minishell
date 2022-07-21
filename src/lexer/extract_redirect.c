/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:49:55 by shogura           #+#    #+#             */
/*   Updated: 2022/07/21 12:07:18 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *extract_outfile(char *input)
{
	char	*ret_file;

	ret_file = NULL;
	
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
		if (ft_strchr(">", input[i]))
			data->exe->outfile = extract_outfile(&input[i]);
		i++;
	}
}
