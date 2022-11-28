/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:01:45 by meskelin          #+#    #+#             */
/*   Updated: 2022/11/21 15:25:33 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findchr(char *str, int c)
{
	int index;

	index = 0;
	while (*str)
	{
		if (*str == c)
			return (index);
		index++;
	}
	return (0);
}

int	ft_strlen(char *str, int find_ln)
{
	int counter;

	counter = 0;
	while (*str)
	{
		if (find_ln && *str == '\n')
		{
			counter++;
			break ;
		}
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_strjoin(char *cache, char *buffer)
{
	char	*result;
	int		index;

	if (!cache)
		result = (char *)malloc(sizeof(*result) * (ft_strlen(buffer, 0) + 1));
	else
		result = (char *)malloc(sizeof(*result) * (ft_strlen(buffer, 0) + ft_strlen(cache, 0) + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (cache && *cache)
		result[index++] = *(cache++);
	while (buffer && *buffer)
		result[index++] = *(buffer++);
	result[index] = '\0';
	return (result);
}
