/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:44:57 by ylarhris          #+#    #+#             */
/*   Updated: 2022/11/14 04:03:38 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char ch);
char	*read_line(int fd, char *str);
char	*till_new_line(char *str);
char	*after_new_line(char *str);
char	*get_next_line(int fd);
#endif