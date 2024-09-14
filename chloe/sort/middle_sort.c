/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:50:06 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 14:04:05 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	prep_for_push(t_stack_node **tmp, t_stack_node *node_cheap, char stack)
{
	int				median;
	t_stack_node	*x;

	x = *tmp;
	if (x == NULL || node_cheap == NULL)
		return ;
	median = find_median(x);
	while (x->nbr != node_cheap->nbr)
	{
		if (stack == 'a')
		{
			if (node_cheap->indice > median)
				rra(tmp);
			else if (node_cheap->indice <= median)
				ra(tmp);
		}
		else if (stack == 'b')
		{
			if (node_cheap->indice > median)
				rrb(tmp);
			else if (node_cheap->indice <= median)
				rb(tmp);
		}
		x = *tmp;
	}
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	sort_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	int				median_a;
	int				median_b;

	cheapest_node = cheap_node(*a);
	median_a = find_median(*a);
	if (median_a == -1)
		return ;
	median_b = find_median(*b);
	if (median_b == -1)
		return ;
	if (cheapest_node->indice <= median_a
		&& cheapest_node->target_node->indice <= median_b)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->indice <= median_a
			&& cheapest_node->target_node->indice <= median_b))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	sort_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}
