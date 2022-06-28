/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ope.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:30:50 by shogura           #+#    #+#             */
/*   Updated: 2022/06/28 20:44:01 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_OPE_H
# define LST_OPE_H

# include <minishell.h>
# include <struct.h>

// lstope func
t_env	*env_node_new(char *env);
t_env	*get_env_last_node(t_env *env_lst);
void	env_node_add_back(t_env **env_lst, t_env *new_node);
void	store_env_lst(t_data *data, char **envp);
void	free_env_lst(t_env *env_lst);

t_token	*lex_node_new(char *token, int type);
t_token	*get_lex_last_node(t_token *lex_lst);
void	lex_node_add_back(t_token **lex_lst, t_token *new_node);
void	store_lex_lst(t_data *data, char **input);
void	free_lex_lst(t_token *lex_lst);
void	print_lex_lst(t_token *lex_lst);

#endif
