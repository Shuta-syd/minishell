/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:30:29 by tharaguc          #+#    #+#             */
/*   Updated: 2022/06/12 01:41:36 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <minishell.h>

void	pwd(void);
void	echo(t_data *data);
void	env(t_data *data);
void	cd(t_data *data);

#endif
