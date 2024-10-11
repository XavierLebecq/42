/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/10 17:20:03 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_cost_rrarrb(t_swap *a, t_swap *b, int nbr)
{
    int index;
    
    index = 0;
    if (ft_index_b(b, nbr))
        index = ft_lstsize2(b) - ft_index_b(b, nbr);
    if ((index < ft_lstsize2(a) - ft_position(a, nbr)) && ft_position(a, nbr))
        index = ft_lstsize2(a) - ft_position(a, nbr);
    return (index);
}
int ft_cost_rarb(t_swap *a, t_swap *b, int nbr)
{
    int index;
    
    index = ft_index_b(b, nbr);
    if (index < ft_position(a, nbr))
        index = ft_position(a, nbr);
    return (index);
}
int ft_cost_rrarb(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = 0;
    if(ft_position(a, nbr))
        index = ft_lstsize2(a) - ft_position(a, nbr);
    index = ft_index_b(b, nbr) + index;
    return (index);
}

int ft_cost_rarrb(t_swap *a, t_swap *b, int nbr)
{
    int index;

    index = 0;
    if (ft_index_b(b, nbr))
        index = ft_lstsize2(b) - ft_index_b(b, nbr);
    index = ft_position(a, nbr) + index;
    return (index);
}