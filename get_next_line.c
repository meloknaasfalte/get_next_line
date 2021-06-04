#include "get_next_line.h"

char	*ft_free(char **r, char *buf)
{
	char	*tmp;

	tmp = *r;
	*r = ft_strjoin(*r, buf);
	free(tmp);
	return (*r);
}

char	*ft_get_line(char **r, char **line, int *flag)
{
	char	*n;

	if (!(*flag))
		*flag = 0;
	n = ft_strchr(*r, '\n');
	if (*flag == 1)
		return (*line);
	if (n == 0)
	{
		*line = ft_strdup(*r);
		*r = NULL;
		*flag = 1;
		return (*line);
	}
	*n = '\0';
	*line = ft_strdup(*r);
	*r = n + 1;
	return (*line);
}

int	ft_free_end(char **begin)
{
	free (*begin);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			result;
	char static	*remainder;
	static int	flag;
	static char	*begin;

	result = 1;
	if (*line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!remainder)
		remainder = ft_strdup("");
	while (result)
	{
		result = read(fd, buf, BUFF_SIZE);
		if (result == -1)
			return (-1);
		if (result == 0)
			break ;
		buf[result] = '\0';
		remainder = ft_free(&remainder, buf);
	}
	if (!begin)
		begin = remainder;
	*line = ft_get_line(&remainder, line, &flag);
	if (!remainder)
		return (ft_free_end(&begin));
	return (1);
}
