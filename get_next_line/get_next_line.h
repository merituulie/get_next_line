/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:02:07 by meskelin          #+#    #+#             */
/*   Updated: 2022/11/21 17:33:05 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEW_LINE_H
# define GET_NEW_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>

// char	*read_fd(int fd, char *cache_ptr);
char	*get_next_line(int fd);

#endif
