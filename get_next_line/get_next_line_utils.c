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
#include  <unistd.h>

char	*read_fd(int fd, char *cache_ptr)
{
	int		bytes_read;
	char	line[BUFFER_SIZE + 1];
	char	*ptr;

	bytes_read = read(fd, line, BUFFER_SIZE);
	ptr = line;
	if (bytes_read < 0)
		return (NULL);
	while (*ptr++)
	line[bytes_read] = '\0';
	return (ptr);
}
