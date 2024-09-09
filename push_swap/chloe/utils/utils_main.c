/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:40:12 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/23 19:18:03 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_all(t_stack_node **a, t_stack_node **b)
{
	if (a)
	{
		if (*a != NULL)
		{
			free_stack(*a);
			*a = NULL;
		}
	}
	if (b)
	{
		if (*b != NULL)
		{
			free_stack(*b);
			*b = NULL;
		}
	}
	if (a)
		free(a);
	if (b)
		free(b);
}

int	count_stack(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
