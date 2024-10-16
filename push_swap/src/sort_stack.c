/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:19 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/16 20:39:07 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(stack_node **a, stack_node **b)
{
	if (ft_stack_size(*a) == 2)
		ft_sa(a);
	if (ft_stack_size(*a) < 2)
		ft_free_stack(a);
	else
	{
		ft_push_elements_to_b(a, b);
		ft_push_elements_to_a(a, b);
		ft_move_min_to_top(a);
	}
}

void	ft_push_elements_to_b(stack_node **a, stack_node **b)
{
	if(ft_stack_size(*a) > 3 && ft_is_unsorted(*a))
		ft_pb(a, b);
	if(ft_stack_size(*a) > 3 && ft_is_unsorted(*a))
		ft_pb(a, b);
	if (ft_stack_size(*a) > 3 && ft_is_unsorted(*a))
		ft_sort_stack_over_three(a, b);
	if (ft_is_unsorted(*a))
		ft_sort_stack_of_three(a);
}

void	ft_sort_stack_over_three(stack_node **a, stack_node **b)
{
	int	i;
	stack_node *temp;

	while (ft_stack_size(*a) > 3 && ft_is_unsorted(*a))
	{
		temp = *a;
		i = ft_calculate_push_cost_b(*a, *b);
		while (i >= 0)
		{
			if (i == ft_cost_rarb_b(*a, *b, temp->nbr))
				i = ft_execute_rarb_b(a, b, temp->nbr);
			else if (i == ft_cost_rrarrb_b(*a, *b, temp->nbr))
				i = ft_execute_rrarrb_b(a, b, temp->nbr);
			else if (i == ft_cost_rarrb_b(*a, *b, temp->nbr))
				i = ft_execute_rarrb_b(a, b, temp->nbr);
			else if (i == ft_cost_rrarb_b(*a, *b, temp->nbr))
				i = ft_execute_rrarb_b(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
}

int	ft_calculate_push_cost_b(stack_node *a, stack_node *b)
{
	int i;
	stack_node	*temp;
	
	temp = a;
	i = ft_cost_rrarrb_b(a, b, a->nbr);

	while (temp)
	{
		if (i > ft_cost_rarb_b(a, b, temp->nbr))
			i = ft_cost_rarb_b(a, b, temp->nbr);
		if (i > ft_cost_rrarrb_b(a, b, temp->nbr))
			i = ft_cost_rrarrb_b(a, b, temp->nbr);
		if (i > ft_cost_rarrb_b(a, b, temp->nbr))
			i = ft_cost_rarrb_b(a, b, temp->nbr);
		if	(i > ft_cost_rrarb_b(a, b, temp->nbr))
			i = ft_cost_rrarb_b(a, b, temp->nbr);
		temp = temp->next;
	}
	return (i);
}

void	ft_push_elements_to_a(stack_node **a, stack_node **b)
{
	int	i;
	stack_node	*temp;

	while (*b)
	{
		temp = *b;
		i = ft_calculate_push_cost_a(*a, *b);
		while (i >= 0)
		{
			if (i == ft_cost_rarb_a(*a, *b, temp->nbr))
				i = ft_execute_rarb_a(a, b, temp->nbr);
			else if (i == ft_cost_rarrb_a(*a, *b, temp->nbr))
				i = ft_execute_rarrb_a(a, b, temp->nbr);
			else if (i == ft_cost_rrarrb_a(*a, *b, temp->nbr))
				i = ft_execute_rrarrb_a(a, b, temp->nbr);
			else if (i == ft_cost_rrarb_a(*a, *b, temp->nbr))
				i = ft_execute_rrarb_a(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
}

int	ft_calculate_push_cost_a(stack_node *a, stack_node *b)
{
	int i;
	stack_node	*temp;

	temp = b;
	i = ft_cost_rrarrb_a(a, b, b->nbr);
	while (temp)
	{
		if (i > ft_cost_rarb_a(a, b, temp->nbr))
			i = ft_cost_rarb_a(a, b, temp->nbr);
		if (i > ft_cost_rrarrb_a(a, b, temp->nbr))
			i = ft_cost_rrarrb_a(a, b, temp->nbr);
		if (i > ft_cost_rarrb_a(a, b, temp->nbr))
			i = ft_cost_rarrb_a(a, b, temp->nbr);
		if (i > ft_cost_rrarb_a(a, b, temp->nbr))
			i = ft_cost_rrarb_a(a, b, temp->nbr);
		temp = temp->next;

	}
	return (i);
}

void	ft_sort_stack_of_three(stack_node **a)
{
	if (ft_find_min_value(*a) == (*a)->nbr)
	{

		ft_rra(a);
		ft_sa(a);
	}
	else if (ft_find_max_value(*a) == (*a)->nbr)
	{
		ft_ra(a);
		if (ft_is_unsorted(*a))
			ft_sa(a);
	}
	else
	{
		if(ft_find_index_in_stack(*a, ft_find_max_value(*a)) == 1)
			ft_rra(a);
		else
			ft_sa(a);
	}
}