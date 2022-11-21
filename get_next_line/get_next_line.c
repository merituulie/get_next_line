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
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s++ != '\0' || *s++ != '\n')
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		index;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
		str[index++] = *(s1++);
	while (*s2 != '\0')
		str[index++] = *(s2++);
	str[index] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*dest;

	str = (char *)src;
	dest = (char *)dst;
	if (!str && !dest && n > 0)
		return (NULL);
	while (n-- > 0)
		*(dest++) = *(str++);
	dest = NULL;
	str = NULL;
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		len;

	len = ft_strlen(s);
	new = (char *)malloc(sizeof(*new) * len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s, len + 1);
	return (new);
}

char	*ft_strchr(const char *s, int a)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (*ptr++ != (unsigned char)a)
	{
		if (*ptr == a)
			return ((char *)ptr);
	}
	ptr = NULL;
	return (NULL);
}

char *ft_trim(char *trimmable)
{
	char	*trimmed;
	int		index;

	index = 0;
	trimmed = (char *)malloc(sizeof(*trimmed) * (ft_strlen(trimmable) + 1));
	while (*trimmable++ != '\n')
		trimmed[index] = *trimmable;
	return (trimmed);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		current[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*next_linebreak;
	char		*temp;

	bytes_read = 1;
	bytes_read = read(fd, current, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (next_linebreak = ft_strchr(current, '\n'))
		{
			cache = ft_strdup(next_linebreak);
			return (ft_trim(current));
		}
		bytes_read = read(fd, current, BUFFER_SIZE);
	}
	return (temp);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("first line: %s\n", get_next_line(fd));
	printf("second line: %s\n", get_next_line(fd));
	return (0);
}
