/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:43:38 by tharaguc          #+#    #+#             */
/*   Updated: 2022/06/14 21:29:10 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	echo(t_data *data)
{
	bool	opt_n;
	char	**inputs;
	int		i;

	opt_n = false;
	inputs = &data->inputs[1];
	if (ft_strcmp(inputs[0], "-n") == 0)
	{
		opt_n = true;
		inputs++;
	}
	i = 0;
	while (inputs[i])
	{
		if (i != 0)
			printf(" ");
		printf("%s", inputs[i++]);
	}
	if (opt_n == false)
		printf("\n");
}
