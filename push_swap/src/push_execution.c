/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:31:55 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/15 21:40:58 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_execute_rarb_b(stack_node **a, stack_node **b, int nbr)
{
    while ((*a)->nbr != nbr && ft_find_insert_position_b(*b, nbr) > 0)
        ft_rr(a, b);
    while ((*a)->nbr != nbr)
        ft_ra(a);
    while (ft_find_insert_position_b(*b, nbr) > 0)
        ft_rb(b);
    ft_pb(a, b);
    return (-1);
}
int ft_execute_rrarrb_b(stack_node **a, stack_node **b, int nbr)
{
    while ((*a)->nbr != nbr && ft_find_insert_position_b(*b, nbr) > 0)
        ft_rrr(a, b);
    while ((*a)->nbr != nbr)
        ft_rra(a);
    while (ft_find_insert_position_b(*b, nbr) > 0)
        ft_rrb(b);
    ft_pb(a, b);
    return (-1);
}
int ft_execute_rrarb_b(stack_node **a, stack_node **b, int nbr)
{
    while ((*a)->nbr != nbr)
        ft_rra(a);
    while (ft_find_insert_position_b(*b, nbr) > 0)
        ft_rb(b);
    ft_pb(a, b);
    return (-1);
}

int ft_execute_rarrb_b(stack_node **a, stack_node **b, int nbr)
{
    while ((*a)->nbr != nbr)
        ft_ra(a);
    while (ft_find_insert_position_b(*b, nbr) > 0)
        ft_rrb(b);
    ft_pb(a, b);
    return (-1);
}

int ft_execute_rarb_a(stack_node **a, stack_node **b, int nbr)
{
    while ((*b)->nbr != nbr && ft_find_insert_position_a(*a, nbr) > 0)
        ft_rr(a, b);
    while ((*b)->nbr != nbr)
        ft_rb(b);
    while (ft_find_insert_position_a(*a, nbr) > 0)
        ft_ra(a);
    ft_pa(a, b);
    return (-1);
}

int ft_execute_rrarrb_a(stack_node **a, stack_node **b, int nbr)
{
    while ((*b)->nbr != nbr && ft_find_insert_position_a(*a, nbr) > 0)
        ft_rrr(a, b);
    while ((*b)->nbr != nbr)
        ft_rrb(b);
    while (ft_find_insert_position_a(*a, nbr) > 0)
        ft_rra(a);
    ft_pa(a, b);
    return (-1);
}

int ft_execute_rrarb_a(stack_node **a, stack_node **b, int nbr)
{
    while (ft_find_insert_position_a(*a, nbr) > 0)
        ft_rra(a);
    while ((*b)->nbr != nbr)
        ft_rb(b);
    ft_pa(a, b);
    return (-1);
}

int ft_execute_rarrb_a(stack_node **a, stack_node **b, int nbr)
{
    while (ft_find_insert_position_a(*a, nbr) > 0)
        ft_ra(a);
    while ((*b)->nbr != nbr)
        ft_rrb(b);
    ft_pa(a, b);
    return (-1);
}