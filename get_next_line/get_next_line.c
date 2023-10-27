/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:41:59 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/23 21:42:04 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = readline(fd, buffer, stat);
	free(buffer);
	stat = store_excess(line);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	

	fd = open("fd1.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	char	*line = get_next_line(fd);
	printf("%s", line);
	free(line);
	char *line2 = get_next_line(fd);
	printf("%s", line2);
	free(line2);
	char *line3 = get_next_line(fd);
	printf("%s", line3);
	free(line3);
	char *line4 = get_next_line(fd);
	printf("%s", line4);
	free(line4);
	char *line5 = get_next_line(fd);
	printf("%s", line5);
	free(line5);
	close(fd);
	close(fd);
	return 0;
}*/
