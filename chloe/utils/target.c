/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:37:21 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 14:07:22 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack_node	*find_min_node(t_stack_node *b)
{
	long			min;
	t_stack_node	*cur_b;
	t_stack_node	*min_node;

	min = LONG_MAX;
	cur_b = b;
	min_node = NULL;
	while (cur_b)
	{
		if (cur_b->nbr < min)
		{
			min = cur_b->nbr;
			min_node = cur_b;
		}
		cur_b = cur_b->next;
	}
	return (min_node);
}

static t_stack_node	*find_best_target(t_stack_node *a_node, t_stack_node *b)
{
	long			best;
	t_stack_node	*cur_b;
	t_stack_node	*target_node;

	best = LONG_MAX;
	cur_b = b;
	target_node = NULL;
	while (cur_b)
	{
		if (cur_b->nbr > a_node->nbr && cur_b->nbr < best)
		{
			best = cur_b->nbr;
			target_node = cur_b;
		}
		cur_b = cur_b->next;
	}
	if (!target_node)
	{
		target_node = find_min_node(b);
	}
	return (target_node);
}

void	find_target(t_stack_node *a, t_stack_node *b)
{
	while (a)
	{
		a->target_node = find_best_target(a, b);
		a = a->next;
	}
}
