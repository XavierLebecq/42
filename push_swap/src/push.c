/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:06 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/11 13:17:57 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pb(t_swap **a, t_swap **b)
{
    t_swap *temp;

    if(!*a)
        return;
    temp = *b;
    *b = *a;
    *a = (*a)->next;
    (*b)->next = temp;
    write(1, "pb\n", 3);
}

void    ft_pa(t_swap **a, t_swap **b)
{
    t_swap *temp;
    
    if (!*b)
        return;
    temp = *a;
    *a = *b;
    *b = (*b)->next;
    (*a)->next = temp;
    write (1, "pa\n", 3);
}