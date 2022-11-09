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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*j_str;

	i = 0;
	j = 0;
	j_str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!j_str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			j_str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		j_str[i + j] = s2[j];
		j++;
	}
	j_str[i + j] = '\0';
	return (j_str);
}
char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (const char)ch)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char *till_new_line(char *s, char *str)
{
	int		i;

	i = 0;
	while(s[i] && s[i] != '\n')
		i++;
	str = (char*)malloc (i + 1);
	if(!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i - 1] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *after_new_line(char *s, char *str)
{
	int		j;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if(!str)
		return (NULL);
	j = 0;
	while (s[i])
		str[j++] = s[++i];
	str[j] = '\0';
	return (str);
}

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
		temp = res;
		res = ft_strjoin(temp, buff);
		free(temp);
		free(buff);
		if (ft_strchr(res, '\n'))
			break;
	}
	line = till_new_line(res, line);
	temp = res;
	res = after_new_line(temp, res);
	free (temp);
	if (!line)
		return (NULL);
	return (line);
}

int mainw()
{
	int i = open("opa.txt", O_RDONLY);
	char *line = NULL;

	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s",get_next_line(i));

	return (0);
}

int main()
{
	mainw();
	// // get_next_line(i);
	// get_next_line(i);
// 	printf("%s",get_next_line(i));
// 	printf("%s",get_next_line(i));
}