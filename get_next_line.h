#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# define	BUFF_SIZE 1

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr (const char *str, int ch);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif