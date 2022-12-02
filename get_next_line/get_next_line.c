/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:00:02 by meskelin          #+#    #+#             */
/*   Updated: 2022/12/02 17:35:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// static void	*ft_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*p;

// 	p = (unsigned char *)b;
// 	while (len-- > 0)
// 	{
// 		*p = (unsigned char)c;
// 		p++;
// 	}
// 	p = NULL;
// 	return (b);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;
// 	size_t	amount;

// 	if (count == 0 || size == 0)
// 		return (ft_calloc(1, 1));
// 	amount = count * size;
// 	if (amount % size != 0 || amount % count != 0)
// 		return (NULL);
// 	ptr = (void *)malloc(sizeof(*ptr) * amount);
// 	if (!ptr)
// 		return (NULL);
// 	ft_memset(ptr, 0, amount);
// 	return (ptr);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	*ptr;

// 	ptr = (unsigned char *)s;
// 	while (*ptr != (unsigned char)c)
// 	{
// 		if (*ptr == '\0')
// 			break ;
// 		ptr++;
// 	}
// 	if (*ptr == (unsigned char)c)
// 		return ((char *)ptr);
// 	ptr = NULL;
// 	return (NULL);
// }

// size_t	ft_strlen(const char *s, int find_nl)
// {
// 	size_t	counter;

// 	counter = 0;
// 	while (s && *s != '\0')
// 	{
// 		counter++;
// 		if (*s == '\n' && find_nl)
// 			break ;
// 		s++;
// 	}
// 	return (counter);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	int		index;

// 	index = 0;
// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		s1 = ft_calloc(1, 1);
// 	str = (char *)ft_calloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1, sizeof(*str));
// 	if (!str)
// 		return (NULL);
// 	while (*s1 != '\0')
// 		str[index++] = *(s1++);
// 	free(s1);
// 	while (*s2 != '\0')
// 		str[index++] = *(s2++);
// 	str[index] = '\0';
// 	return (str);
// }

char	*trim_cache(char *cache)
{
	char	*rest;
	size_t	eof;
	size_t	index;

	while (cache && *cache && *cache != '\n')
		cache++;
	if (*cache == '\n')
		cache++;
	eof = ft_strlen(cache, 0);
	rest = (char *)ft_calloc(eof, sizeof(*rest));
	if (!rest)
		return (NULL);
	index = 0;
	while (index <= eof)
		rest[index++] = *(cache++);
	cache = NULL;
	return (rest);
}

char	*parse_nl(char *cache)
{
	char	*line;
	size_t	lb;
	size_t	index;

	lb = ft_strlen(cache, 1);
	line = (char *)ft_calloc(lb, sizeof(*line));
	if (!line)
		return (NULL);
	index = 0;
	while (index <= lb)
		line[index++] = *(cache++);
	return (line);
}

char	*read_fd(int fd, char *cache)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(*buffer));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			break ;
		cache = ft_strjoin(cache, buffer);
		if (!cache || ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cache = read_fd(fd, cache);
	if (!cache)
		return (NULL);
	line = parse_nl(cache);
	if (!line)
	{
		free(cache);
		return (NULL);
	}
	cache = trim_cache(cache);
	return (line);
}

// int main()
// {
// 	int fd = open("empty", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// }
