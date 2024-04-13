/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:59:00 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/13 01:33:33 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	ft_find_nl(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] != '\0' && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return (1);
			i += 1;
		}
		lst = lst->next;
	}
	return (0);
}

void	ft_create_lst(t_list **lst, char *buffer)
{
	t_list	*new_lst;
	t_list	*last;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
	{
		free(buffer);
		return ;
	}
	new_lst->content = buffer;
	new_lst->next = NULL;
	if (!*lst)
		*lst = new_lst;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_lst;
	}
}
/*
void	ft_create_lst(t_list **lst, char *buffer)
{
	t_list	*last_lst;
	t_list	*new_lst;

	last_lst = ft_lstlast(*lst);
	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return ;
	if (!last_lst)
		*lst = new_lst;
	else
		last_lst->next = new_lst;
	new_lst->content = buffer;
	new_lst->next = NULL;
}
*/

void	ft_read(t_list **lst, int fd)
{
	int		read_bytes;
	char	*buffer;

	while (!ft_find_nl(*lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!read_bytes)
		{
			free(buffer);
			return ;
		}
		buffer[read_bytes] = '\0';
		ft_create_lst(lst, buffer);
	}
}

char	*concatenate_lst(t_list *lst)
{
	int		len;
	char	*line;

	if (!lst)
		return (NULL);
	len = ft_lstsize_nl(lst);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_create_line(lst, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, NULL, 0) < 0)
		return (NULL);
	ft_read(&lst, fd);
	if (!lst)
		return (NULL);
	final_line = concatenate_lst(lst);
	ft_rest(&lst);
	return (final_line);
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("usage: %s <file\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf ("GNL = %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
*/
