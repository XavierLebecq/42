/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:31:55 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/11 17:35:58 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_apply_rarb_b(t_swap **a, t_swap **b, int nbr)
{
    while ((*a)->nbr != nbr && ft_index_b(*b, nbr) > 0)
        ft_rr(a, b);
    while ((*a)->nbr != nbr)
        ft_ra(a);
    while (ft_index_b(*b, nbr) > 0)
    {
        printf("test");
        ft_rb(b);
    }
    ft_pb(a, b);
    return (-1);
}
int ft_apply_rrarrb_b(t_swap **a, t_swap **b, int nbr)
{
    while ((*a)->nbr != nbr && ft_index_b(*b, nbr) > 0)
        ft_rrr(a, b);
    while ((*a)->nbr != nbr)
        ft_rra(a);
    while (ft_index_b(*b, nbr) > 0)
        ft_rrb(b);
    ft_pb(a, b);
    return (-1);
}
int ft_apply_rrarb_b(t_swap **a, t_swap **b, int nbr)
{
    while ((*a)->nbr != nbr)
        ft_rra(a);
    while (ft_index_b(*b, nbr) > 0)
        ft_rb(b);
    ft_pb(a, b);
    return (-1);
}

int ft_apply_rarrb_b(t_swap **a, t_swap **b, int nbr)
{
    while ((*a)->nbr != nbr)
        ft_ra(a);
    while (ft_index_b(*b, nbr) > 0)
        ft_rrb(b);
    ft_pb(a, b);
    return (-1);
}