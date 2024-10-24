/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:13:46 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 11:14:28 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_elements_to_a(t_stack_node **a, t_stack_node **b)
{
	int				i;
	t_stack_node	*temp;

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

int	ft_calculate_push_cost_a(t_stack_node *a, t_stack_node *b)
{
	int				i;
	t_stack_node	*temp;

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

void	ft_move_min_to_top(t_stack_node **a)
{
	int	i;

	i = ft_find_index_in_stack(*a, ft_find_min_value(*a));
	if (i < ft_stack_size(*a) - i)
	{
		while ((*a)->nbr != ft_find_min_value(*a))
			ft_ra(a);
	}
	else
	{
		while ((*a)->nbr != ft_find_min_value(*a))
			ft_rra(a);
	}
}
