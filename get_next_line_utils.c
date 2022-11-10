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
