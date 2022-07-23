/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:13 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/22 16:08:35 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_dp(char **dp);

void	reset(t_shell *shell)
{
	size_t i;

	i = 0;
	free(shell->input);
	free(shell->exe->infile);
	free(shell->exe->outfile);
	while (i < shell->exe->cmd_cnt)
	{
		free_dp(shell->exe->cmds[i].args);
		i++;
	}
}

void	free_dp(char **dp)
{
	size_t i;
	i = 0;
	while (dp[i])
		free(dp[i++]);
	free(dp);
}
