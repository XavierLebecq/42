/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:13:46 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:24:23 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_elements_to_a(stack_node **a, stack_node **b)
{
	int			i;
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
	int			i;
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
		if (ft_find_index_in_stack(*a, ft_find_max_value(*a)) == 1)
			ft_rra(a);
		else
			ft_sa(a);
	}
}
