/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:11:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/22 16:02:49 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "minishell.h"

//utils
void	motd(void);
void	store_env_lst(t_shell *data, char **envp);
char	*ms_getenv(t_shell *data, char *name);
void	reset(t_shell *shell);

// signal
void	handle_signal(int signal);

//builtins
void	exit_(char *msg, int status);

//lexer
void	lexer(t_shell *shell);
void	free_t_exe(t_shell *data);
char	*extract_arg(t_shell *data, char *input, char **start, size_t *i);
char	*store_quoted_arg(t_shell *data, char *input, size_t *i, char quote);
char	*expand_env(char *arg, t_shell *data, bool quoted);
char	*create_expanded_arg(char *arg, t_list **val, size_t len);
char	**split_by_pipe(char *input, size_t cmd_cnt);
size_t	count_arg_len(char *arg, t_list **val, t_list **key);
size_t	count_args(char *input);
size_t	count_cmds(char *input);
void	copy_env_val(char **dst, size_t *j, t_list **env_val);
void	store_redirect_in_out(t_shell *data, char *input);

// executor
void executor(t_shell *shell);
int		ft_execvp(char *file, char *argv[]);

#endif
