/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:20:01 by ylarhris          #+#    #+#             */
/*   Updated: 2022/11/14 03:32:29 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		readd;

	readd = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	while (check_new_line(str) == 0 && readd)
	{
		readd = read(fd, buff, BUFFER_SIZE);
		if (readd == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[readd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*till_new_line(char *str)
{
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	return (ft_substr(str, 0, i + 1));
}

char	*after_new_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			temp = ft_substr(str, i + 1, ft_strlen(str));
			free (str);
			return (temp);
		}
		i++;
	}
	free (str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*res[OPEN_MAX];
	char		*before;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res[fd] = read_line(fd, res[fd]);
	if (!res[fd])
		return (NULL);
	before = till_new_line(res[fd]);
	res[fd] = after_new_line(res[fd]);
	return (before);
}
