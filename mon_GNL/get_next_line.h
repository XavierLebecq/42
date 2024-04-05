/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakren <krakren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:33:06 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/04 23:28:28 by krakren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	char			reste[BUFFER_SIZE + 1];
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
int		ft_strchr_index(const char *s, int c);
void    ft_lstclear(t_list **lst);



#endif
