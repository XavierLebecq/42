/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:04:24 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/07 16:16:21 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_next_line(int fd)
{
        char    *str;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

        read(fd, str, BUFFER_SIZE);
		printf ("str = %s\nFIN", str);

	}

	int	main(int argc, char **argv)
	{
	int	fd;

	if (argc < 2)
	{
		printf("usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	get_next_line(fd);
	return 0;
}
