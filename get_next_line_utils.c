/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denysdudka <denysdudka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:11:29 by ddudka            #+#    #+#             */
/*   Updated: 2024/10/26 12:41:49 by denysdudka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	unsigned long	i;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(0));
	else if (count * size / size != count)
		return (NULL);
	tmp = malloc (count * size);
	if (!tmp)
		return (NULL);
	while (i < size * count)
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			cc;

	cc = (char)c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == cc)
		res = (char *)&s[i];
	return (res);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tab = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	int			i;
	char		*tmp_ptr;

	i = 0;
	tmp_ptr = malloc (sizeof(char) * ft_strlen(s1)+1);
	if (!tmp_ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp_ptr[i] = s1[i];
		i++;
	}
	tmp_ptr[i] = '\0';
	return (tmp_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	counter;
	char	*subs;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	counter = 0 ;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	subs = (char *) malloc(sizeof(char) * len + 1);
	if (!subs)
		return (NULL);
	while (counter < len)
	{
		subs[counter] = s[start + counter];
		counter++;
	}
	subs[counter] = '\0';
	return (subs);
}


