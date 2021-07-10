#include "get_next_line.h"

void	ft_strclr(char *s)
{
	int			i;

	i = 0;
	while (s && *(s + i))
	{
		*(s + i) = '\0';
		i++;
	}
}

void	ft_free(char **str, char *p)
{
	char		*tmp;

	tmp = *str;
	free (tmp);
	tmp = NULL;
	*str = p;
}

char	*check_remainder(char *remainder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (remainder)
	{
		p_n = ft_strchr(remainder, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_strclr(remainder);
		}
	}
	else
	{
		*line = ft_strdup("");
	}
	return (p_n);
}

char	*ft_return(char **remainder, char *line, int result, char *filter)
{
	if (line[0] != filter[0] || result)
		return (line);
	if (*remainder)
	{
		free(*remainder);
		*remainder = 0;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			result;
	char		*p_n;
	static char	*remainder;
	char 		*line;

	line = NULL;
	result = 1;
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, buf, 0))
		return (NULL);
	p_n = check_remainder(remainder, &line);
	while (result && !p_n)
	{
		result = read(fd, buf, BUFF_SIZE);
		buf[result] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			ft_free(&remainder, ft_strdup(++p_n));
		}
		ft_free(&line, ft_strjoin(line, buf));
	}
	printf("(%s)\n {%s}\n", line, remainder);
	return (ft_return(&remainder, line, result, ""));
}
//int main(void)
//{
//	int 	fd;
//	char 	*res;
//	int 	counter;
//
//	counter = 0;
//	fd = open("text_try.txt", O_RDONLY);
//	while (1)
//	{
//		res = get_next_line(fd);
//		printf("#%i, res:  - %s\n", counter, res);
//		free(res);
//		counter++;
//		if (res == NULL)
//			break;
//	}
//}
