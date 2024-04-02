/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:32:47 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/02 17:47:06 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*container;
	int	i;

	i = 0;

	if (fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read (fd, line, BUFFER_SIZE);
	line [BUFFER_SIZE] = '\0';
	container = line;
	printf("container = %s\n", container);
	return (line);
}

int	main(int argc, char **argv)
{
	if (argc < 2) 
	{
        	printf("Usage: %s <file>\n", argv[0]);
        	return 1;
    	}

	int	fd;
	char	*saved_line;

	fd = open (argv[1], O_RDONLY);

	saved_line = get_next_line(fd);
	printf("=%s=\n", saved_line);
	free (saved_line);

	close (fd);
	return (0);
}


