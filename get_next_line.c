/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:06:25 by mschaub           #+#    #+#             */
/*   Updated: 2023/01/13 15:01:52 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_makeremainder(int fd, char *remainder)
{
	char	*buff;
	int		bytes;

	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(remainder, '\n') && bytes)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(remainder);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		remainder = ft_strjoin(remainder, buff);
	}
	free(buff);
	return (remainder);
}

char	*ft_newremainder(char *remainder)
{
	int		j;
	int		i;
	char	*ret;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	ret = ft_calloc(sizeof(char), ((ft_strlen(remainder) - i + 1)));
	if (!ret)
	{
		free(remainder);
		return (NULL);
	}
	j = 0;
	i++;
	while (remainder[i])
		ret[j++] = remainder[i++];
	ret[j] = '\0';
	free(remainder);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_makeremainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_read_line(remainder);
	remainder = ft_newremainder(remainder);
	return (line);
}
/*
#include <stdio.h>

int main() {
    
	char	*line;
	int i = 1;
	
	int fd = open("test.txt", O_RDONLY);
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s\n", i, line);
		i++;
	}

    return 0;
}
*/
