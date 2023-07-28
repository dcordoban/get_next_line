
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	int i = 6;
	char *str;

	if (argc == 50)
		return (2);
	fd = open(argv[1], O_RDONLY);
	while (i-- > 0)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
	return (0);
}
