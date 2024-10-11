/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:39:12 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/11 17:20:34 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_index_b(t_swap *b, int nbr)
{
    int index;
    t_swap *temp;
    
    index = 1;
    if(nbr > b->nbr && nbr < ft_lstlast2(b)->nbr)
        index = 0;
    else if (nbr > ft_int_max(b) || nbr < ft_int_min(b))
        index = ft_position(b, ft_int_max(b));
    else
    {
        temp = b->next;
        while(b->nbr < nbr || temp->nbr >nbr)
        {
            b = b->next;
            temp = b->next;
            index++;
        }
    }
    return (index);
}

int ft_position(t_swap *a, int nbr)
{
    int index;

    index = 0;
    while (a->nbr != nbr)
    {
        index++;
        a = a->next;
    }
//  a->index = 0;
    return (index);
}