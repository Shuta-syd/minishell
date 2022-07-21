/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:49:55 by shogura           #+#    #+#             */
/*   Updated: 2022/07/21 11:53:54 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	store_redirect_in_out(t_shell *data, char *input)
{
	size_t	i;
	char	*infile;
	char	*outfile;

	i = 0;
	infile = NULL;
	outfile = NULL;
	while (input[i])
	{
		if (ft_strchr("<>", input[i]))
		{
			
		}
	}
}
