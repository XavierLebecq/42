/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gestion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:12:24 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 14:03:55 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	gestion_cost(t_stack_node *a, t_stack_node *b)
{
	top_cost(a);
	top_cost(b);
	bot_cost(a);
	bot_cost(b);
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	find_target(a, b);
	gestion_cost(a, b);
	total_cost(a);
	cheap_node(a);
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	find_target(b, a);
	gestion_cost(b, a);
	total_cost(b);
	cheap_node(b);
}

void	min_on_top(t_stack_node **x)
{
	int				median;
	t_stack_node	*min;

	median = find_median(*x);
	min = find_min(*x);
	while ((*x)->nbr != min->nbr)
	{
		if (min->nbr >= median)
		{
			ra(x);
		}
		else
		{
			rra(x);
		}
	}
}
