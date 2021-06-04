#include "get_next_line.h"

int	main()
{
	char	*line;
	int		fd;
	int		res;

	fd = open("text_try.txt", O_RDONLY);
	while ((res = get_next_line(fd, &line)))
	{
		printf("%s : %i\n", line, res);
		free(line);
	}
	get_next_line(fd, &line);
	printf("%s : %i\n", line, res);
	free(line);
	return (0);
}
