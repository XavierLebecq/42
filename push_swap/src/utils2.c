/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:39:12 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/15 03:05:08 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_index_b(stack *b, int nbr)
{
    int index;
    stack *temp;
    
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

int ft_index_a(stack *a, int nbr)
{
    int index;
    stack *temp;

    index = 1;
    if (nbr < a->nbr && nbr > ft_lstlast2(a)->nbr)
        index = 0;
    else if (nbr > ft_int_max(a) || nbr < ft_int_min(a))
        index = ft_position(a, ft_int_min(a));
    else
    {
        temp = a->next;
        while (a->nbr > nbr || temp->nbr < nbr)
        {
            a = a->next;
            temp = a->next;
            index++;
        }
    }
    return (index);
}



int ft_position(stack *a, int nbr)
{
    int index;

    index = 0;
    while (a->nbr != nbr)
    {
        index++;
        a = a->next;
    }
    return (index);
}