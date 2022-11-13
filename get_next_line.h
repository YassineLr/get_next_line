/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:44:13 by ylarhris          #+#    #+#             */
/*   Updated: 2022/11/09 01:57:56 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE
# endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
int	check_new_line(char *str);
size_t ft_strlen(const char *str);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *s1);
char *ft_substr(char *s, int start, int len);
char	*read_line(int fd, char *str);
char	*before_new_line(char *str);
char	*after_new_line(char *str);

#endif

# endif