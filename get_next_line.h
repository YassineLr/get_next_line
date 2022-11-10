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

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
# endif

size_t	ft_strlen(const char *str);
char	*till_new_line(char *s, char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
char	*after_new_line(char *s, char *str);
char *get_next_line(int fd);

# endif