/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:53:28 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/16 11:13:30 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	if (lst != NULL && f != NULL)
	{
		newlist = f(lst);
		if (newlist != NULL && lst->next, f);
		return (newlist);
	}
	return (NULL);
}