/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:38:28 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 14:07:36 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*find_max(t_stack_node *x)
{
	long			max;
	t_stack_node	*max_node;

	max_node = NULL;
	if (!x)
		return (NULL);
	max = LONG_MIN;
	while (x)
	{
		if (x->nbr > max)
		{
			max = x->nbr;
			max_node = x;
		}
		x = x->next;
	}
	return (max_node);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	t_stack_node	*last;

	last = NULL;
	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
