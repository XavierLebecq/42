/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:09:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/14 18:17:56 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct blabla
{
	char			*content;
	struct blabla	*next;
}					t_list;


void	ft_lst(t_list **lst)
{
	printf("2valeur de lst = %p\n", lst);
	printf("2adresse de lst = %p\n", &lst);
	printf("2valeur de *lst = %p\n", *lst);
}

void	ft_list(t_list *lst)
{
	printf("3valeur de lst = %p\n", lst);
	printf("3adresse de lst = %p\n", &lst);
}

void ft_liste(t_list lst)
{

}

int	main()
{
	char	*str;
	static t_list *lst = NULL;

	printf ("1valeur de lst = %p\n", lst);
	printf ("1adresse de lst = %p\n", &lst);

	ft_lst(&lst);
	ft_list(lst);
//	ft_liste(*lst);
	return (0);
}
