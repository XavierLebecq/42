/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:21:17 by xlebecq           #+#    #+#             */
/*   Updated: 2024/09/12 12:23:01 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_libft	*ft_lstlast(t_libft *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
