/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:27:26 by mschaub           #+#    #+#             */
/*   Updated: 2023/01/12 15:11:56 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = s;
	if (str)
	{
		while (*str)
		{
			if ((char)c == *str)
				return (str);
			str++;
		}
		if ((char)c == 0)
			return (str);
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (!s1 && !s2)
		return (NULL);
	ret = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			ret[i] = s1[i];
	while (s2[j])
		ret[i++] = s2[j++];
	free(s1);
	return (ret);
}

char	*ft_read_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
