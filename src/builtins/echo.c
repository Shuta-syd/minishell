/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:07:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/06/30 19:16:29 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	echo(t_data *data)
// {
// 	bool	opt_n;
// 	char	**inputs;
// 	int		i;

// 	opt_n = false;
// 	inputs = &data->inputs[1];
// 	if (ft_strcmp(inputs[0], "-n") == 0)
// 	{
// 		opt_n = true;
// 		inputs++;
// 	}
// 	i = 0;
// 	while (inputs[i])
// 	{
// 		if (i != 0)
// 			printf(" ");
// 		printf("%s", inputs[i++]);
// 	}
// 	if (opt_n == false)
// 		printf("\n");
// }