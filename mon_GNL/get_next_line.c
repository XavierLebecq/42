/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:04:24 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/07 17:25:17 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_element;
	
	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);

}
char	*get_next_line(int fd)
{
	char	*str;
	int		read_bytes;
	t_list	*new_node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	read_bytes = read(fd, str, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(str);
		return (NULL);
	}
	str[read_bytes] = '\0';
	printf ("str = %s\n", str);
	new_node = ft_lstnew(str);
	printf ("new_node = %s\n", new_node->content);
	return (str);
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
	close (fd);
	return (0);
}
