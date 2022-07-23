/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:01:38 by shogura           #+#    #+#             */
/*   Updated: 2022/07/23 20:07:03 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_check(int fd, bool *newline_b, char *line_buf)
{
	int		read_byte;

	read_byte = 0;
	line_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line_buf == NULL)
		return (NULL);
	read_byte = read(fd, line_buf, BUFFER_SIZE);
	if (read_byte == -1 || read_byte == 0)
	{
		free(line_buf);
		return (NULL);
	}
	if (ft_strchr(line_buf, '\n') != NULL)
		*newline_b = true;
	return (line_buf);
}

char	*read_and_join(int fd, char *line_buf, bool *newline_b)
{
	char	*read_buf;
	char	*ret_line;
	int		read_byte;

	ret_line = NULL;
	read_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (read_buf == NULL)
	{
		free(line_buf);
		return (NULL);
	}
	read_byte = read(fd, read_buf, BUFFER_SIZE);
	if (read_byte == -1)
	{
		free(line_buf);
		free(read_buf);
		return (NULL);
	}
	ret_line = ft_strjoin(line_buf, read_buf);
	free(line_buf);
	free(read_buf);
	if (ft_strchr(ret_line, '\n') != NULL || read_byte == 0)
		*newline_b = true;
	return (ret_line);
}

char	*split_and_ret(char *line_buf, char **save_buf,
		char *ret_line, size_t	len)
{
	if (line_buf == NULL)
		return (NULL);
	while (line_buf[len] != '\0' && line_buf[len] != '\n')
		len++;
	ret_line = ft_substr(line_buf, 0, len + 1);
	if (ret_line == NULL)
	{
		free(line_buf);
		return (NULL);
	}
	if (ft_strchr(ret_line, '\n') == NULL)
		len -= 1;
	if (ft_strlen(line_buf) - (len + 1) && ft_strlen(line_buf) != 1)
	{
		*save_buf = ft_substr(line_buf, len + 1, ft_strlen(line_buf) - len);
		if (*save_buf == NULL)
		{
			free(ret_line);
			ret_line = NULL;
		}
	}
	free(line_buf);
	return (ret_line);
}

char	*get_next_line(int fd)
{
	char		*ret_line;
	char		*line_buf;
	static char	*save_buf;
	bool		newline_b;

	line_buf = NULL;
	ret_line = NULL;
	newline_b = false;
	if (newline_b == false)
	{
		if (save_buf == NULL)
			line_buf = read_and_check(fd, &newline_b, line_buf);
		else if (save_buf != NULL)
		{
			line_buf = read_and_join(fd, save_buf, &newline_b);
			save_buf = NULL;
		}
		while (newline_b == false && line_buf != NULL)
			line_buf = read_and_join(fd, line_buf, &newline_b);
	}
	return (split_and_ret(line_buf, &save_buf, ret_line, 0));
}
