#include "get_next_line.h"

int main()
{
	int fd;
	fd = open("file", O_RDONLY);
	for (int i = 0; i < 3; i++)
		get_next_line(fd);
}