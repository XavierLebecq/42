/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:06 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/15 03:05:08 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pb(stack **a, stack **b)
{
    stack *temp;

    if(!*a)
        return;
    temp = *b;
    *b = *a;
    *a = (*a)->next;
    (*b)->next = temp;
    write(1, "pb\n", 3);
}

void    ft_pa(stack **a, stack **b)
{
    stack *temp;
    
    if (!*b)
        return;
    temp = *a;
    *a = *b;
    *b = (*b)->next;
    (*a)->next = temp;
    write (1, "pa\n", 3);
}