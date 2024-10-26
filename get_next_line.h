/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denysdudka <denysdudka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:11:34 by ddudka            #+#    #+#             */
/*   Updated: 2024/10/26 12:58:21 by denysdudka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_BONUS_H
// # define GET_NEXT_LINE_BONUS_H
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 15
// # endif
// # define MAX_FD 10240
// # include <stdlib.h>
// # include <unistd.h>
// # include <fcntl.h>
// # include <stdio.h>

// char	*get_next_line(int fd);

// char	*ft_strdup(char *s);
// size_t	ft_strlen(char *s);
// char	*ft_substr(char *s, unsigned int start, size_t len);
// char	*ft_strjoin(char *s1, char *s2);
// void	fill_str(char *res, char *s1, char *s2);

// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *remainded_string(char *line);
char *read_line(char *buffer,char *left_c, int fd);

#endif