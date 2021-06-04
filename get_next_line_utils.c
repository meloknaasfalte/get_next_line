#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l;
	size_t	len1;
	size_t	len2;
	char	*r;

	l = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	r = malloc(sizeof(char) *(len1 + len2 + 1));
	if (!r)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[l])
		r[i++] = s2[l++];
	r[i] = '\0';
	return (r);
}

char	*ft_strchr (const char *str, int ch)
{
	size_t	i;
	char	c;

	i = 0;
	c = (char)ch;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	l;
	char	*ds ;

	l = 0;
	i = ft_strlen(s);
	ds = malloc(i + 1);
	if (!ds)
		return (NULL);
	while (s[l])
	{
		ds[l] = s[l];
		l++;
	}
	ds[l] = '\0';
	return (ds);
}
