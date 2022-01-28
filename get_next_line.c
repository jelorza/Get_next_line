/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:10:21 by jelorza-          #+#    #+#             */
/*   Updated: 2022/01/28 15:08:17 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*rest_buff;
	int			bit_counter;
	char		*line;

	bit_counter = 1;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (ft_find_char(rest_buff, '\n') && bit_counter != 0)
	{
		bit_counter = read(fd, buff, BUFFER_SIZE);
		buff[bit_counter] = 00;
		if (bit_counter == -1)
		{
			free(buff);
			return (NULL);
		}
		rest_buff = ft_join(rest_buff, buff, bit_counter);
	}
	line = ft_line_out(rest_buff);
	rest_buff = ft_new_rest(rest_buff);
	free(buff);
	return (line);
}

char	*ft_line_out(char *rest_buff)
{
	char	*line_out;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (!rest_buff)
		return (NULL);
	if (ft_find_char(rest_buff, '\n'))
		return (rest_buff);
	//if (rest_buff[0] == '\n')
	//	line_out = malloc(sizeof(char) * 2);  -----------para repasar por que creo qie es necesario pero sin esto me funciona bien tambien-------------
//	else
//	{
		while (rest_buff[i] != '\n')
			i++;
		line_out = malloc(sizeof(char) * i + 2);
//	}
	while (i + 1 > 0)
	{
		line_out[k] = rest_buff[k];
		i--;
		k++;
	}
	line_out[k] = 00;
	return (line_out);
}

char	*ft_new_rest(char *rest_buff)
{
	char	*aux_rest_buff;
	size_t	count;
	size_t	i;

	i = 0;
	if (!rest_buff || ft_find_char(rest_buff, '\n'))
		return (NULL);
	if (rest_buff[0] == '\n' && rest_buff[1] == 00)
	{
		free(rest_buff);
		return 00;
	}
	while (rest_buff[i] != '\n')
		i++;
	if (rest_buff[i] == '\n' && rest_buff[i + 1] == 00)
	{
		free(rest_buff);
		return 00;
	} 
	count = 0;
	aux_rest_buff = malloc(sizeof(char) * ( ft_strlen(rest_buff) - ++i + 1));
	while (rest_buff[i])
	{
		aux_rest_buff[count] = rest_buff[i];
		count++;
		i++;
	}
	aux_rest_buff[count] = 00;
	free(rest_buff);
	return (aux_rest_buff);
}
