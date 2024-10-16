/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/16 20:03:00 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_cost_rrarrb_b(stack_node *a, stack_node *b, int nbr)
{
    int i;
    
    i = 0;
    if (ft_find_insert_position_b(b, nbr))
        i = ft_stack_size(b) - ft_find_insert_position_b(b, nbr);
    if ((i < ft_stack_size(a) - ft_find_index_in_stack(a, nbr)) && ft_find_index_in_stack(a, nbr))
        i = ft_stack_size(a) - ft_find_index_in_stack(a, nbr);
    return (i);
}
int ft_cost_rarb_b(stack_node *a, stack_node *b, int nbr)
{
    int i;
    
    i = ft_find_insert_position_b(b, nbr);
    if (i < ft_find_index_in_stack(a, nbr))
        i = ft_find_index_in_stack(a, nbr);
    return (i);
}
int ft_cost_rrarb_b(stack_node *a, stack_node *b, int nbr)
{
    int i;

    i = 0;
    if(ft_find_index_in_stack(a, nbr))
        i = ft_stack_size(a) - ft_find_index_in_stack(a, nbr);
    i = ft_find_insert_position_b(b, nbr) + i;
    return (i);
}

int ft_cost_rarrb_b(stack_node *a, stack_node *b, int nbr)
{
    int i;

    i = 0;
    if (ft_find_insert_position_b(b, nbr))
        i = ft_stack_size(b) - ft_find_insert_position_b(b, nbr);
    i = ft_find_index_in_stack(a, nbr) + i;
    return (i);
}

int ft_cost_rarb_a(stack_node *a, stack_node *b, int nbr)
{
    int i;

    i = ft_find_insert_position_a(a, nbr);
    if (i < ft_find_index_in_stack(b, nbr))
        i = ft_find_index_in_stack(b, nbr);
    return (i);
}

int ft_cost_rrarrb_a(stack_node *a, stack_node *b, int nbr)
{
    int i;

    i = 0;
    if (ft_find_insert_position_a(a, nbr))
        i = ft_stack_size(a) - ft_find_insert_position_a(a, nbr);
    if ((i < (ft_stack_size(b) - ft_find_index_in_stack(b, nbr))) && ft_find_index_in_stack(b, nbr))
        i = ft_stack_size(b) - ft_find_index_in_stack(b, nbr);
    return (i);
}

int ft_cost_rarrb_a(stack_node *a, stack_node *b, int nbr)
{
    int i;

    i = 0;
    if (ft_find_index_in_stack(b, nbr))
        i = ft_stack_size(b) - ft_find_index_in_stack(b, nbr);
    i = ft_find_insert_position_a(a, nbr) + i;
    return (i);
}

int ft_cost_rrarb_a(stack_node *a, stack_node *b, int nbr)
{
    int i;

    i = 0;
    if (ft_find_insert_position_a(a, nbr))
        i = ft_stack_size(a) - ft_find_insert_position_a(a, nbr);
    i = ft_find_index_in_stack(b, nbr) + i;
    return (i);
}