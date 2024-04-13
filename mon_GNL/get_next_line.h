/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:25:13 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/12 23:44:11 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_create_lst(t_list **lst, char *buffer);
void	ft_read(t_list **lst, int fd);
int		ft_find_nl(t_list *lst);
char	*concatenate_lst(t_list *lst);
void	ft_rest(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize_nl(t_list *lst);
void	ft_create_line(t_list *lst, char *line);
void	ft_clear_lst(t_list **lst, t_list *lst_rest, char *rest);

#endif
