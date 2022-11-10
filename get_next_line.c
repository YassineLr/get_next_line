/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:21:38 by ylarhris          #+#    #+#             */
/*   Updated: 2022/11/09 03:36:02 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char	*res;
    char		*line;
    char		*temp;
	char 		*buff;
    int			readd;

	buff = NULL;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return(NULL);
	temp = NULL;
    readd = 1;
	while(readd > 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		readd = read(fd, buff, BUFFER_SIZE);
		if (readd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readd] = '\0';
		res = ft_strjoin(res, buff);
		free(buff);
		if (ft_strchr(res, '\n'))
			break;
	}
	line = till_new_line(res, line);
	if (!*line)
		return (NULL);
	temp = res;
	res = after_new_line(temp, res);
	free (temp);
	return (line);
}
