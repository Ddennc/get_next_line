/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddudka <ddudka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:11:29 by ddudka            #+#    #+#             */
/*   Updated: 2024/12/09 15:41:57 by ddudka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *source)
{
	char			*copy;
	unsigned int	index;

	copy = (char *)malloc(ft_strlen(source) + 1);
	if (!copy)
		return (NULL);
	index = 0;
	while (source[index])
	{
		copy[index] = source[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_substr(char *str, unsigned int start_pos, size_t sub_len)
{
	size_t			index;
	char			*substring;

	if (!str)
		return (NULL);
	if (start_pos > ft_strlen(str))
		return (malloc(1));
	if (sub_len > ft_strlen(str + start_pos))
		sub_len = ft_strlen(str + start_pos);
	substring = malloc((sub_len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	index = 0;
	while (index < sub_len)
	{
		substring[index] = str[start_pos + index];
		index++;
	}
	substring[index] = '\0';
	return (substring);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *str, int ch)
{
	unsigned int	index;
	char			character;

	character = (char)ch;
	index = 0;
	while (str[index])
	{
		if (str[index] == character)
			return ((char *)&str[index]);
		index++;
	}
	if (str[index] == character)
		return ((char *)&str[index]);
	return (NULL);
}
