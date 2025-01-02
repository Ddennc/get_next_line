/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denysdudka <denysdudka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:11:32 by ddudka            #+#    #+#             */
/*   Updated: 2025/01/02 20:01:26 by denysdudka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_buffer_to_remainder(char *buffer, char *remainder, int fd)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(remainder);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remainder);
}

char	*extract_line_from_remainder(char *remainder)
{
	size_t	i;
	char	*line;
	char	*line_text;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line_text = ft_substr(remainder, 0, i + (remainder[i] == '\n'));
	line = NULL;
	if (line_text)
		line = malloc((ft_strlen(line_text) + 1) * sizeof(char));
	if (!line)
		return (free(line_text), NULL);
	i = -1;
	while (line_text[++i])
		line[i] = line_text[i];
	line[i] = '\0';
	free(line_text);
	return (line);
}

char	*update_remainder(char *line)
{
	char	*new_remainder;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	new_remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!new_remainder)
		return (NULL);
	if (*new_remainder == '\0')
	{
		free(new_remainder);
		new_remainder = NULL;
	}
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remainder[MAX_FD];
	char		*updated_remainder;

	line = NULL;
	updated_remainder = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(remainder[fd]), remainder[fd] = NULL, NULL);
	if (!remainder[fd])
		remainder[fd] = ft_strdup("");
	remainder[fd] = read_buffer_to_remainder(buffer, remainder[fd], fd);
	free(buffer);
	if (!remainder[fd])
		return (NULL);
	line = extract_line_from_remainder(remainder[fd]);
	if (line)
		updated_remainder = update_remainder(remainder[fd]);
	free(remainder[fd]);
	remainder[fd] = updated_remainder;
	return (line);
}
