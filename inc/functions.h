/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:11:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/26 20:41:54 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minishell.h"

//utils
void	motd(void);
void	store_env_lst(t_shell *data, char **envp);
char	*ms_getenv(t_shell *data, char *name);
char	*get_next_line(int fd);
void	reset(t_shell *shell);
void	copy_lst_content(char **dst, size_t *j, t_list **lst);

// env
t_env	*env_node_new(char *env);
void	env_node_add_back(t_env **env_lst, t_env *new_node);

// signal
void	handle_signal(int signal);

//builtins
void	exit_(char *msg, char *status);
int		ft_echo(char **argv);
void	ft_env(t_shell *shell);
void	ft_pwd(void);
int		ft_cd(char *dir, t_shell *shell);
int		ft_export(t_shell *shell, char *arg);
void	ft_unset(t_shell *shell, char *key);

//lexer
int		lexer(t_shell *shell);
char	*extract_arg(t_shell *data, char *input, char **start, size_t *i);
char	*store_quoted_arg(t_shell *data, char *input, size_t *i, char quote);
char	*expand_env(char *arg, t_shell *data, bool quoted);
char	*create_expanded_arg(t_shell *data, char *arg,
			t_list **val, size_t len);
char	**split_by_pipe(t_shell *data, char *input, size_t cmd_cnt);
size_t	count_arg_len(char *arg, t_list **val, t_list **key);
size_t	count_args(char *input);
size_t	count_cmds(char *input);
void	copy_env_val(char **dst, size_t *j, t_list **env_val);
void	store_redirect_in_out(t_shell *data, char *input);
bool	arg_is_quoted(t_shell *data);
void	exit_session(t_shell *data, int status, char *msg);

// heredoc
char	*extract_sign(char *input);
size_t	count_input_len(t_list *heredoc, char *input);
void	heredoc(t_shell *data);

// executor
void	executor(t_shell *shell);
int		ft_execvp(char *file, char *argv[], t_shell *shell);

#endif
