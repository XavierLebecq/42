/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakren <krakren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:32:47 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/04 23:33:28y krakren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void read_and_store(int fd, t_list **head_ref)
{
    char    buff[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    t_list  *new_node = NULL;

    while ((bytes_read = read(fd, buff, buFFER_SIZE)) > 0)
    {
        buff[bytes_read] = '\0';
        new_node = ft_lstnew(buff);
        if (!new_node)
            break;
        ft_lstadd_back(head_ref, new_node);
        if (ft_strchr_index(buff, '\n'))
           new_node->content = strdup(buff + ft_strchr_index(buff, '\n') + 1);
    }
}
static char *assemble_line(t_list **head_ref)
{
    char    *line;
    t_list  *temp;
    size_t  total_len = 0;
    char    *found_newline;

    temp = *head_ref;
    while (temp)
    {
        found_newline = ft_strchr(temp->content, '\n');
        if (found_newline)
        {
            // Ajouter la longueur jusqu'à '\n', plus un pour inclure '\n' lui-même
            total_len += (found_newline - temp->content) + 1;
            break;
        }
        else
            total_len += ft_strlen(temp->content);
        temp = temp->next;
    }

    line = malloc(sizeof(char) * (total_len + 1));
    if (!line) return NULL;

    char *temp_line = line;
    temp = *head_ref;
    while (temp)
    {
        found_newline = ft_strchr(temp->content, '\n');
        if (found_newline)
        {
            // Copier jusqu'à '\n', plus un pour inclure '\n' lui-même
            size_t len = (found_newline - temp->content) + 1;
            ft_memcpy(temp_line, temp->content, len);
            temp_line += len;
            // Gérer le reste si nécessaire...
            break;
        }
        else
        {
            size_t len = ft_strlen(temp->content);
            ft_memcpy(temp_line, temp->content, len);
            temp_line += len;
        }
        temp = temp->next;
    }
    *temp_line = '\0';

    return line;
}

/*
    input   ->   {a}{b}{c}{\n}{d}{e}{f}
    BUFFER_READ[0] ->   {a}{b}{c}{\n}{d}
    actuel output  ->   {a}{b}{c}{\n}
    BUFFER_READ[1]  ->   {e}{f}{\n}
    output attendu ->   {d}{e}{f}{\n}
    ft_strjoin("reste", "BUFFER_READ") -> "resteBUFFER_READ"

    Apres avoir trouver '\n' doit mettre dans reste ce qui est apres '\n'
*/

char *get_next_line(int fd)
{
    static t_list   *head = NULL;
	char			*line;

    if (fd < 0 || BUFFER_SIZE < 1)
    {
	    return (NULL);
	}
	else
	{
		read_and_store(fd, &head);
	}
	if (!head)
		return (NULL);
	line = assemble_line(&head);
    // ft_lstclear(&head);
    head = head->next;
    return (line);
}


int	main(int argc, char **argv)
{
	int		fd;
    char    *line;
    int  i = 0;

	if (argc < 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
    while (i < 10000000)
    {
        line = get_next_line(fd);
        if (!line)
            return (printf("next_line[%d] = %s\n", i, line));
        printf("next_line[%d] = %s", i, line);
        free(line);
        i++;
    }
	close(fd);
	return (0);
}
