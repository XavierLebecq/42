





char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == '\0')
		return (*s);
	return (NULL);
}
		
			
