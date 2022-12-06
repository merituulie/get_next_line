/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:02:07 by meskelin          #+#    #+#             */
/*   Updated: 2022/12/05 18:36:21 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_COUNT
#  define FD_COUNT 10
# endif

size_t	ft_strlen(char *str);
int		ft_findchr(char *str, char c);
char	*ft_strjoin_free(char *cache, char *buffer);
char	*ft_init_str(void);
char	*get_next_line(int fd);

#endif
