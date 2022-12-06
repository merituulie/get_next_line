/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:01:45 by meskelin          #+#    #+#             */
/*   Updated: 2022/12/05 19:01:51 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}

int	ft_findchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin_free(char *cache, char *buffer)
{
	char	*result;
	int		index_r;
	int		index_c;
	size_t	len;

	len = (ft_strlen(cache) + ft_strlen(buffer));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result || !cache || !buffer)
		return (NULL);
	index_r = 0;
	index_c = 0;
	while (cache[index_c] != '\0')
		result[index_r++] = cache[index_c++];
	index_c = 0;
	while (buffer[index_c] != '\0')
		result[index_r++] = buffer[index_c++];
	result[index_r] = '\0';
	free(cache);
	return (result);
}

char	*ft_init_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}
