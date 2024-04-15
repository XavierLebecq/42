/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:23:44 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/14 17:04:11 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_create_list(t_list **lst, char *buffer)
{
	t_list	*new;
	t_list	*last;

	new = malloc(t_list *)malloc(sizeof(t_list));
	if (!new)	
	{
		free(buffer);
		return ;
	}
	new->content = buffer;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}	
}


t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_read(t_list **lst, int fd)
{
	int		read_bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	read_bytes = read (fd, buffer, BUFFER_SIZE);
	if (!read_bytes)
	{
		free(buffer);
		return ;
	}
	buffer[read_bytes] = '\0';
	printf ("buffer= %s\n", buffer);
	ft_create_lst(lst, buffer)
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, NULL, 0) < 0)
		return (NULL);
	ft_read(&lst, fd);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open (argv[1], O_RDONLY);
	printf("GNL= %s\n", get_next_line(fd));
	close (fd);
	return (0);
}
