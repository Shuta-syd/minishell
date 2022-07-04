/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:25:18 by shogura           #+#    #+#             */
/*   Updated: 2022/07/04 20:34:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

bool consume(char **input, char target)
{
	if (**input == target)
	{
		(*input)++;
		return true;
	}
	return false;
}

t_ast	*node_new(NodeKind kind, t_ast *left, t_ast*right)
{
	t_ast	*node = calloc(1, sizeof(t_ast));
	node->kind = kind;
	node->left = left;
	node->right = right;

	return node;
}

t_ast *node_new_val(int num, char *val)
{
	t_ast *node = calloc(1, sizeof(t_ast));
	if (val == NULL)
	{
		node->kind = ND_NUM;
		node->num = num;
		node->val = NULL;
	}
	else
	{
		node->kind = ND_VAL;
		node->num = 0;
		node->val = val;
	}
	return node;
}

t_ast	*input(char *input)
{
	t_ast	*node;

	printf("input() ->%s\n\n", input);
	node = cmd_line(&input);
	return node;
}

t_ast *cmd_line(char **input)
{
	t_ast	*node;
	int	i;

	i = 0;
	printf("1. cmd_line() ->%s\n\n", *input);
	node = seq_cmd(input);
	printf("2. cmd_line() ->%s\n\n", *input);
	if (consume(input, ';'))
		node = node_new(ND_DELI, node, cmd_line(input));
	return node;
}

t_ast *seq_cmd(char **input)
{
	t_ast	*node;

	printf("1. seq_cmd() ->%s\n\n", *input);
	node = cmd(input);
	printf("2. seq_cmd() ->%s\n\n", *input);
	node = node_new(ND_CMD, node, expr(input));
	printf("3. seq_cmd() ->%s\n\n", *input);
	return node;
}

t_ast *cmd(char **input){
	int i;
	t_ast	*node;
	char	*cmd;

	i = 0;
	printf("1. cmd() ->%s\n\n", *input);
	while ((*input)[i] && (*input)[i] != ' ')
		i++;
	cmd = ft_substr(*input, 0, i);
	*input += i + 1; 
	printf("2. cmd() ->%s\n\n", *input);
	node = node_new_val(0, cmd);
	return node;
}

t_ast *expr(char **input)
{
	t_ast	*node;

	printf("1. expr() ->%s\n\n", *input);
	node = mul(input); // 10
	printf("2. expr() ->%s\n\n", *input);
	if (consume(input, '+'))
		node = node_new(ND_ADD, node, mul(input)); // 50
	printf("3. expr() ->%s\n\n", *input);
	return node;
}

t_ast *mul(char **input)
{
	t_ast	*node;

	printf("1. mul() ->%s\n\n", *input);
	node = primary(input);
	printf("2. mul() ->%s\n\n", *input);
	if (consume(input, '*')) // in * mark?
		node = node_new(ND_MUL, node, primary(input));
	printf("3. mul() ->%s\n\n", *input);
	return	node;
}

t_ast *primary(char **input)
{
	int	num;
	t_ast	*node;

	//"(" ")"のときexpr()
	printf("1. primary() ->%s\n\n", *input);
	if (consume(input, '('))
	{
		node = expr(input);
		if (consume(input, ')') == true)
			return node;
	}
	printf("2. primary() ->%s\n\n", *input);
	num = atoi(*input);
	printf("[num]->%d\n\n", num);
	while (ft_isdigit(**input))
		(*input)++;
	printf("3. primary() ->%s\n\n", *input);
	return node_new_val(num, NULL);
}

void	print(t_ast *ast)
{
	if (ast->left)
		print(ast->left);
	printf("Nodekind->%d num->%d val->%s\n", ast->kind, ast->num, ast->val);
	if (ast->right)
		print(ast->right);
}

int main(int argc, char const *argv[])
{
	char	*test_cmd = "echo 5*6+(10+50)";
	t_ast	*ast;

	ast = input(test_cmd);
	//printf("Nodekind->%d num->%d val->%s", ast->kind, ast->num, ast->val);
	print(ast);
	return 0;
}
