/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/15 00:35:37 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_cost_rrarrb_b(t_swap *a, t_swap *b, int nbr)
{
    int index;
    
    index = 0;
    if (ft_index_b(b, nbr))
        index = ft_lstsize2(b) - ft_index_b(b, nbr);
    if ((index < ft_lstsize2(a) - ft_position(a, nbr)) && ft_position(a, nbr))
        index = ft_lstsize2(a) - ft_position(a, nbr);
    return (index);
}
int ft_cost_rarb_b(t_swap *a, t_swap *b, int nbr)
{
    int index;
    
    index = ft_index_b(b, nbr);
    if (index < ft_position(a, nbr))
        index = ft_position(a, nbr);
    return (index);
}
int ft_cost_rrarb_b(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = 0;
    if(ft_position(a, nbr))
        index = ft_lstsize2(a) - ft_position(a, nbr);
    index = ft_index_b(b, nbr) + index;
    return (index);
}

int ft_cost_rarrb_b(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = 0;
    if (ft_index_b(b, nbr))
        index = ft_lstsize2(b) - ft_index_b(b, nbr);
    index = ft_position(a, nbr) + index;
    return (index);
}

int ft_cost_rarb_a(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = ft_index_a(a, nbr);
    if (index < ft_position(b, nbr))
        index = ft_position(b, nbr);
    return (index);
}

int ft_cost_rrarrb_a(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = 0;
    if (ft_index_a(a, nbr))
        index = ft_lstsize2(a) - ft_index_a(a, nbr);
    if ((index < (ft_lstsize2(b) - ft_position(b, nbr))) && ft_position(b, nbr))
        index = ft_lstsize2(b) - ft_position(b, nbr);
    return (index);
}

int ft_cost_rarrb_a(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = 0;
    if (ft_position(b, nbr))
        index = ft_lstsize2(b) - ft_position(b, nbr);
    index = ft_index_a(a, nbr) + index;
    return (index);
}

int ft_cost_rrarb_a(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = 0;
    if (ft_index_a(a, nbr))
        index = ft_lstsize2(a) - ft_index_a(a, nbr);
    index = ft_position(b, nbr) + index;
    return (index);
}