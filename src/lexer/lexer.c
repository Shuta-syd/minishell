/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:01 by shogura           #+#    #+#             */
/*   Updated: 2022/07/15 18:10:00 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void lexer(t_shell *shell)
{
	size_t	i;
	char **input;

	i = 0;
	input = ft_split(shell->input, '|');
	if (input == NULL)
		exit(1);
	while (input[i])
	{
		if (ft_strchr(input[i]), )
		{
			/* code */
		}

		i++;
	}

	return ;
}
