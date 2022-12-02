/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:01:45 by meskelin          #+#    #+#             */
/*   Updated: 2022/12/02 17:40:53 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len-- > 0)
	{
		*p = (unsigned char)c;
		p++;
	}
	p = NULL;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	amount;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	amount = count * size;
	if (amount % size != 0 || amount % count != 0)
		return (NULL);
	ptr = (void *)malloc(sizeof(*ptr) * amount);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, amount);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (*ptr != (unsigned char)c)
	{
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	if (*ptr == (unsigned char)c)
		return ((char *)ptr);
	ptr = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *s, int find_nl)
{
	size_t	counter;

	counter = 0;
	while (s && *s != '\0')
	{
		counter++;
		if (*s == '\n' && find_nl)
			break ;
		s++;
	}
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		index;

	index = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	str = (char *)ft_calloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1, sizeof(*str));
	if (!str)
		return (NULL);
	while (*s1 != '\0')
		str[index++] = *(s1++);
	free(s1);
	while (*s2 != '\0')
		str[index++] = *(s2++);
	str[index] = '\0';
	return (str);
}
