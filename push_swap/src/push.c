/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:06 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/10 10:43:16 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pb(t_swap **a, t_swap **b, int index)
{
    t_swap *temp;

    if(!*a)
        return;
    temp = *b;
    *b = *a;
    *a = (*a)->next;
    (*b)->next = temp;
    if (index == 0)
        write(1, "pb\n", 3);
}