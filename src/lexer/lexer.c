/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:05 by shogura           #+#    #+#             */
/*   Updated: 2022/07/07 13:17:00 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	DELIMITERS ";|{}$&\'\"'\n'<> "

	DELIMITERSが来たら区切る

	例
	cat < file | grep a | wc -l > file2 > file3; echo a
	echo "hello w"'orld'; cat<file|wc -> 14 + 1
	echo "This is $USER"  'This is $USER' ->
	cat<file|grep 42|wc;echo "This is $USER";
	cat<file|grep 42|wc;echo 'This is $USER';
*/
//cat | grep

bool	is_delimiter_prev_next(char *input)
{
	size_t	i;
	char	prev;
	char	next;

	i = 0;
	if (input[i + 1] == '\0')
		return (false);
	prev = input[i];
	next = input[i + 2];
	if (ft_strchr(DELIMITERS, prev) == 0)
	{
		if (ft_strchr(DELIMITERS, next) == 0)
			return (false);
	}
	return (true);
}

size_t	count_len_deled_str(char *input)
{
	size_t	i;
	size_t	len;
	size_t	len_ws;

	i = 0;
	len_ws = 0;
	len = ft_strlen(input);
	while (input[i])
	{
		if (input[i] == ' ')
			len_ws++;
		i++;
	}
	return (len - len_ws);
}

char	*del_white_space(char *input)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ret;

	i = 0;
	j = 0;
	len = count_len_deled_str(input);
	ret = ft_calloc(len, sizeof(char));
	if (ret == NULL)
		return (NULL);//error
	while (input[j])
	{
		if (input[j] != ' ' || is_delimiter_prev_next(&input[j - 1]) == false)
		{
			ret[i] = input[j];
			i++;
		}
		j++;
	}
	return (ret);
}

char	*fetch_deli(char **input)
{
	//delimiterを切り取る
}

char *fetch_word(char **input)
{
	size_t	end;
	char	*input_cp;
	char	*ret_word;

	if (ft_strchr(DELIMITERS, **input))
		return (fetch_deli(input));
	end = 0;
	input_cp = *input;
	while (**input)
	{
		if (ft_strchr(DELIMITERS, **input))
			break ;
		(*input)++;
		end++;
	}
	ret_word = ft_substr(input_cp, 0, end);
	if (ret_word == NULL)
		return (NULL);
	return (ret_word);
}

void	store_lex_lst(t_data *data, char *input)
{
	t_token	*node;
	char	*word;

	word = fetch_word(&input);
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
	char	*input;

	input = del_white_space(data->input);
	store_lex_lst(data, input);
	/*
		print_lex_lst(data->lex_lst);
	*/
}
