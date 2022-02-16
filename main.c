#include "get_next_line.h"

int main()
{
	int fd;

	fd = open("file", O_RDONLY);
	//for(int i; i < 3; i++)
	char *temp = get_next_line(fd);
	printf("%s", temp);
	temp = get_next_line(fd);
	printf("%s", temp);
	temp = get_next_line(fd);
	printf("%s", temp);

	free(temp);

}