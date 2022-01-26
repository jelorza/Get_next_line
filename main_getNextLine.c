#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

int main(void)
{
	int fd;
	char *line;
	int j;
	j = 0;

	line = "1";
	fd = open("/Users/jelorza-/Desktop/get_next_line/gnlTester/files/big_line_no_nl", O_RDWR);
	if (fd == -1)
		printf("Ha habido un error");
	else
	{
		printf("Se ha abierto correctamente\n");
	while (line)
	{
			line = get_next_line(fd);
			printf("%s-----", line);
			j++;
		}
	}
	return(0);
}
