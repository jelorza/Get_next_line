#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char	*get_next_line(int fd)
{
	char *buff;
	int bit_amount;

	if(fd == -1 || BUFFER_SIZE <= 0)
	{	
		printf("Error en el inicio de la funcion, el descriptor no ha sido abierto o el buffer_size es incorrecto");
		return (NULL);
	}
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bit_amount = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE + 1] = 00;
	if (!buff)
	{
		printf("El archivo esta vacio");
		return (0);
	}
	return (buff);
	free(buff);	
}
