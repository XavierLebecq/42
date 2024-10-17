/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_execution_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:31:55 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:30:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_execute_rarb_b(t_stack_node **a, t_stack_node **b, int nbr)
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

int	ft_execute_rrarrb_b(t_stack_node **a, t_stack_node **b, int nbr)
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

int	ft_execute_rrarb_b(t_stack_node **a, t_stack_node **b, int nbr)
{
	while ((*a)->nbr != nbr)
		ft_rra(a);
	while (ft_find_insert_position_b(*b, nbr) > 0)
		ft_rb(b);
	ft_pb(a, b);
	return (-1);
}

int	ft_execute_rarrb_b(t_stack_node **a, t_stack_node **b, int nbr)
{
	while ((*a)->nbr != nbr)
		ft_ra(a);
	while (ft_find_insert_position_b(*b, nbr) > 0)
		ft_rrb(b);
	ft_pb(a, b);
	return (-1);
}
