/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:06 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:30:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (!*a || !*a)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (!*b || !*b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	write(1, "pa\n", 3);
}
