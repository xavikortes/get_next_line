#include "project/get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd = open("./project/get_next_line.h", O_RDONLY);

	char *line;
	int i = 1;

	while ((line = get_next_line(fd)))
	{
		printf("%i: %s", i, line);
		i++;
		free(line);
	}
	return (0);
}
