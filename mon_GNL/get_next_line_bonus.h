/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:30:58 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/15 22:46:17 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

void    ft_create_lst(t_list **lst, char *buffer);
void    ft_read(t_list **lst, int fd);
int ft_lstsize_nl(t_list *lst);
char    *ft_concatenate_lst(t_list *lst);
void    ft_create_line(t_list *lst, char *line);
char    *get_next_line(int fd);
int	ft_findnl(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif
