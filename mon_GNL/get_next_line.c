/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:59:00 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/12 00:11:08 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_read(int fd, t_list **head)
{
	int		*read_bytes;
	char	*buffer;

	while (!ft_find_nl(*head))
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER SIZE + 1));
		if (!buffer)
			return ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!read_bytes)
		{
			free(buffer);
			return ;
		}
		buffer[read_bytes] = '\0';
		ft_lstadd_back(head, buffer);
	}
}

void	ft_lstadd_back(t_list **head, char *buffer)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = ft_lst last(*head);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*head = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

int	ft_find_nl(t_list *node)
{
	int	i;

	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->content[i] != '\0' && i < BUFFER_SIZE)
		{
			if (node->content[i] == '\n')
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

char	*concatenate_nodes(t_list *head)
{
	int		len;
	char	*line;

	if (!head)
		return (NULL);
	len = ft_lstsize(head);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strcpy(head, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	char			*final_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read (fd, NULL, 0) < 0)
		return (NULL);
	ft_read(fd, &head);
	if (!head)
		return (NULL);
	final_line = concatenate_nodes(head);
	ft_lstclean(&list);
	return (final_line);
}
