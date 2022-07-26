/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:01:13 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/26 19:46:55 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_dp(char **dp);

void	reset(t_shell *shell)
{
	size_t	i;

	i = 0;
	if (shell->input)
		free(shell->input);
	if (shell->exe == NULL)
		return ;
	if (shell->exe->infile)
		free(shell->exe->infile);
	if (shell->exe->infile)
		free(shell->exe->outfile);
	if (shell->exe->cmds == NULL)
		return ;
	while (i < shell->exe->cmd_cnt)
	{
		if (shell->exe->cmds[i].args == NULL)
			return ;
		free_dp(shell->exe->cmds[i].args);
		i++;
	}
	free(shell->exe->cmds);
	free(shell->exe);
}

void	free_dp(char **dp)
{
	size_t	i;

	i = 0;
	while (dp[i])
		free(dp[i++]);
	free(dp);
}
