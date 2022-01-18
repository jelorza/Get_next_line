#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

int main(void)
{
	int fd;
	char *line;

	line = "1";
	fd = open("big_line_with_nl", O_RDWR);
	if (fd == -1)
		printf("Ha habido un error");
	else
		printf("Se ha abierto correctamente\n");
	while (*line)
	{
		line  = get_next_line(fd);
		printf("%s", line);
	}
	return(0);
}
