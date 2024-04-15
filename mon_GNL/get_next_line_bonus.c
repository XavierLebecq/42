/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:23:44 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/15 23:03:29 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void    ft_read(t_list **lst, int fd)
{
    int     read_bytes;
    char    *buffer;

    while(!ft_findnl(*lst))
    {
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
        ft_create_lst(lst, buffer);
    }
}

int	ft_findnl(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] != '\0')
		{
			if (lst->content[i] == '\n')
				return (1);
			i = i + 1;
		}
		lst = lst->next;
	}
}

void	ft_create_lst(t_list **lst, char *buffer)
{
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
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

t_list  *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

char    *ft_concatenate_lst(t_list *lst)
{
    int len;
    char    *line;

    if (!lst)
        return (NULL);
    len = ft_lstsize_nl(lst);
    line = (char *)malloc(len + 1);
    if (!line)
        return (NULL);
    ft_create_line(lst, line);
    return (line);
}

int	ft_lstsize_nl(t_list *lst)
{
	int	i;
	int	j;
	
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i] != '\0')
		{
			if (lst->content[i] == '\n')
			{
		    	j++;
				return (j);
			}
			i++;
			j++;
		}
		lst = lst->next;
	}
	return (j);
}

void	ft_create_line(t_list *lst, char *line)
{
	int	i;
	int j;

	j = 0;
	while (lst)
	{
		i = 0;	
		while(lst->content[i] != '\0')
		{
			if (lst->content[i] == '\n')
			{
				line[j] = '\n';
				line[j + 1] = '\0';
				return ;
			}
			line[j] = lst->content[i];
			i++;
			j++;
		}
		lst = lst->next;
	}
	line[i] = '\0';
}		

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, NULL, 0) < 0)
		return (NULL);
	ft_read(&lst, fd);
	if (!lst)
		return (NULL);
	line = ft_concatenate_lst(lst);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("erreur open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
		printf("GNL = %s", line);
	close (fd);
	return (0);
}
