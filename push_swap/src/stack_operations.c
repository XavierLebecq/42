/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:11:27 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:24:00 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(stack_node **a)
{
	stack_node	*temp;

	if (!*a || !((*a)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	write(1, "sa\n", 3);
}

void	ft_rra(stack_node **a)
{
	stack_node	*temp;
	int			i;

	if (!a || !(*a)->next)
		return ;
	i = 0;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_ra(stack_node **a)
{
	stack_node	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = ft_stack_last_node(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rr(stack_node **a, stack_node **b)
{
	stack_node	*temp;

	if (!a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = ft_stack_last_node(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	temp = *b;
	*b = ft_stack_last_node(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_rrr(stack_node **a, stack_node **b)
{
	stack_node	*temp;
	int			i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	temp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	ft_rrr2(b);
}
