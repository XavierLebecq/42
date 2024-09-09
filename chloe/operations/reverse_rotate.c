/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:22:19 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 13:09:50 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack_node **x)
{
	t_stack_node	*last;
	t_stack_node	*before_last;
	t_stack_node	*first_node;

	if (!*x || !(*x)->next)
		return ;
	first_node = *x;
	last = *x;
	before_last = *x;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	last->next = first_node;
	first_node->prev = last;
	before_last->next = NULL;
	last->prev = NULL;
	*x = last;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
