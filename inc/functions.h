/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:11:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/21 11:45:45 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "minishell.h"

//utils
void	motd(void);
void	store_env_lst(t_shell *data, char **envp);
char	*ms_getenv(t_shell *data, char *name);

// signal
void	handle_signal(int signal);

//builtins
void	exit_(char *msg, int status);

//lexer
void	lexer(t_shell *shell);
void	free_t_exe(t_shell *data);
char	*extract_arg(t_shell *data, char *input, char **start, size_t *i);
char	*store_quoted_arg(t_shell *data, char *input, size_t *i, char quote);
char	*expand_env(char *arg, t_shell *data);
char	*create_expanded_arg(char *arg, t_list **val, size_t len);
void	copy_env_val(char **dst, size_t *j, t_list **env_val);
size_t	count_arg_len(char *arg, t_list **val, t_list **key);

#endif
