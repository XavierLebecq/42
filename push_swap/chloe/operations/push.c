/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:21:20 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 12:21:31 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack_node **destination, t_stack_node **source)
{
	t_stack_node	*top;

	if (*source == NULL)
		return ;
	top = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	top->next = NULL;
	if (*destination)
		(*destination)->prev = top;
	top->next = *destination;
	top->prev = NULL;
	*destination = top;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
