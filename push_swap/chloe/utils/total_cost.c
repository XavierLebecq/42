/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:39:00 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 12:39:07 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	total_cost(t_stack_node *a)
{
	t_stack_node	*current_a;
	t_stack_node	*target_b;

	current_a = a;
	while (current_a)
	{
		current_a->total_cost = current_a->cost;
		if (current_a->target_node)
		{
			target_b = current_a->target_node;
			current_a->total_cost += target_b->cost;
		}
		current_a = current_a->next;
	}
}
