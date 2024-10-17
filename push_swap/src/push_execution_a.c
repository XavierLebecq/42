/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_execution_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:16:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:24:23 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_execute_rarb_a(stack_node **a, stack_node **b, int nbr)
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

int	ft_execute_rrarrb_a(stack_node **a, stack_node **b, int nbr)
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

int	ft_execute_rrarb_a(stack_node **a, stack_node **b, int nbr)
{
	while (ft_find_insert_position_a(*a, nbr) > 0)
		ft_rra(a);
	while ((*b)->nbr != nbr)
		ft_rb(b);
	ft_pa(a, b);
	return (-1);
}

int	ft_execute_rarrb_a(stack_node **a, stack_node **b, int nbr)
{
	while (ft_find_insert_position_a(*a, nbr) > 0)
		ft_ra(a);
	while ((*b)->nbr != nbr)
		ft_rrb(b);
	ft_pa(a, b);
	return (-1);
}
