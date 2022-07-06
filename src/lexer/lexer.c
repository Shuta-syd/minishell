/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 00:29:39 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	DELIMITERS ";|{}$&\'\"'\n'<> "

	DELIMITERSが来たら区切る

	例
	c| ->  16 + 1
	echo "hello w"'orld'; cat<file|wc -> 14 + 1
	echo "This is $USER"  'This is $USER' ->
	cat<file|grep 42|wc;echo "This is $USER";
	cat<file|grep 42|wc;echo 'This is $USER';
*/

char *fetch_deli(char **input, char *delis)
{
	//delimiterを切り取る
}

char *fetch_word(char **input, char *delis)
{
	size_t	end;
	char	*input_cp;
	char	*ret_word;

	if (ft_strchr(delis, (**input)))
		return (fetch_deli(input, delis));
	end = 0;
	input_cp = *input;
	while (**input)
	{
		if (ft_strchr(delis, (**input)))
			break ;
		(*input)++;
		end++;
	}
	ret_word = ft_substr(input_cp, 0, end);
	if (ret_word == NULL)
		; //error
	return (ret_word);
}

void	store_lex_lst(t_data *data)
{
	t_token	*node;
	char	*word;

	word = fetch_word(&data->input, DELIMITERS);
	if (word == NULL)
		return ; // error
	printf("word->[%s] input->[%s]\n", word, data->input);
	node = lex_node_new(word, NOTYPE); // search_type
	lex_node_add_back(&data->lex_lst, node);
	free(node);
	free(word);
	store_lex_lst(data);
}

void	lexer(t_data *data)
{
	store_lex_lst(data);
	/*
		print_lex_lst(data->lex_lst);
	*/
}
