/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:48:15 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/20 14:53:45 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (del != NULL && alst != NULL)
    {
        del((*alst)->content, sizeof((*alst)->content));
        free(*alst);
        *alst = NULL;
    }
}
}
