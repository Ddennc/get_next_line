/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denysdudka <denysdudka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:11:32 by ddudka            #+#    #+#             */
/*   Updated: 2024/12/09 12:22:35 by denysdudka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(char *buffer,char *left_c, int fd)
{
	ssize_t chars_read;
	char *tmp;
	
	chars_read = 1;
	while(chars_read)
	{
	chars_read = read(fd,buffer,BUFFER_SIZE);
	if (chars_read < 0)
	{
			free(left_c);
			return (NULL);
		}
	else if (!chars_read)
	break;
	buffer[chars_read] = '\0';
	if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (left_c);
} 

char *remainded_string(char *line)
{
	char *left_c;
	ssize_t i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (NULL);
	left_c = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line[i + 1] = 0;
	return (left_c);
}
char *get_next_line(int fd)
{
	char *line;
	char *buf;
	static char *left_c;
	
	buf = calloc(BUFFER_SIZE + 1,sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buf);
		left_c = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = read_line(buf,left_c,fd);
	free(buf);
	if (!line)
		return (NULL);
	left_c = remainded_string(line);
	return (line);
}


