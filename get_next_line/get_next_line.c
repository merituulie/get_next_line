/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:00:02 by meskelin          #+#    #+#             */
/*   Updated: 2022/11/21 17:33:54 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*read_fd(int fd, char *cache)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, O_RDONLY);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		cache = ft_strjoin(cache, buffer);
		if (!cache)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_findchr(cache, '\n') > 0)
			break ;
	}
	free(buffer);
	return (cache);
}

char	*parse_next_line(char *cache)
{
	char	*line;
	int		index;

	index = 0;
	line = (char *)malloc(sizeof(*line) * ft_strlen(cache, 1) + 1);
	while (cache && *cache)
		line[index++] = *(cache++);
	line[index] = '\0';
	cache = NULL;
	return (line);
}

char	*trim_cache(char *cache)
{
	char	*temp;

	while (cache && *cache && *cache != '\n')
		cache++;
	temp = ++cache;
	free(cache);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(0, 0, O_RDONLY))
		return (NULL);
	cache = read_fd(fd, cache);
	line = parse_next_line(cache);
	if (!line)
	{
		free(cache);
		return (NULL);
	}
	cache = trim_cache(cache);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("first line: %s\n", get_next_line(fd));
	printf("second line: %s\n", get_next_line(fd));
	return (0);
}
