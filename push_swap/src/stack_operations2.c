/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:11:41 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 11:13:51 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_stack_node **b)
{
	t_stack_node	*temp;

	if (!b || !(*b)->next)
		return ;
	temp = *b;
	*b = ft_stack_last_node(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rrb(t_stack_node **b)
{
	t_stack_node	*temp;
	int				i;

	i = 0;
	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

void	ft_rrr2(t_stack_node **b)
{
	t_stack_node	*temp;
	int				i;

	i = 0;
	temp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rrr\n", 4);
}

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
