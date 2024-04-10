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

char	*concatenate_nodes(t_list *head)
{
	size_t	total_lenght = 0;
	t_list	*current;
	char	*result;
	char	*dest;

	current = head;
	while (current != NULL)
	{
		total_lenght = total_lenght + ft_strlen(current->content);
		current = current->next;
	}
	result = malloc(total_lenght + 1);
	if (!result)
		return (NULL);
	dest = result;
	current = head;
	while (current != NULL)
	{
		ft_strlcpy(dest, current->content, ft_strlen(current->content) + 1);
		dest += ft_strlen(current->content);
		current = current->next;
	}
	*dest = '\0';
	return (result);
}

/*
static int	add_line_to_list(t_list **head, char *buffer, ssize_t read_bytes)
{
	t_list  *new_node;
	char	*content;
	ssize_t	i;
	int		includes_newline;
	int		addtional_lenght;
	
	i = 0;
	additional_lenght = 0;
	includes_newline = 0;
	while (i < read_bytes)
	{
		if (buffer[i] == '\n')
		{
			includes_newline = 1;
			break;
		}
		i++;
	}
	if (includes_newline = 1)
		additional_lenght = 1
	content = (char *)malloc(sizeof(char) * (i + 1 + additional_lenght + 1));
	if (!content)
		return (-1);
 	ft_strlcpy(content, buffer, i + 1 + additional_length);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		return (-1);
	}
	ft_lstadd_back(head, new_node);
	return includes_newline;
}
*/

char	*get_next_line(int fd)
{	
	static t_list	*head = NULL;
	char			*buffer;
	int				read_bytes;
	char			*newline_ptr;
	char			*final_line;
	
	newline_ptr = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			newline_ptr = ft_strchr(buffer, '\n');
			ft_lstadd_back(&head, ft_lstnew(buffer));
		}
		if (newline_ptr != NULL)
			break;
	}
	free(buffer);
	if (read_bytes < 0)
		return (NULL);
	final_line = concatenate_nodes(head);
	return (final_line);
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
	printf("GNL = %s\n", get_next_line(fd));
	close (fd);
	return (0);
}
