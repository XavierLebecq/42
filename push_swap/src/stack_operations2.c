/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:11:41 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:24:23 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(stack_node **b)
{
	stack_node	*temp;

	if (!b || !(*b)->next)
		return ;
	temp = *b;
	*b = ft_stack_last_node(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rrb(stack_node **b)
{
	stack_node	*temp;
	int			i;

	if (!*b || !(*b)->next)
		return ;
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
	write(1, "rrb\n", 4);
}

void	ft_rrr2(stack_node **b)
{
	stack_node	*temp;
	int			i;

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
