/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:49:39 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/28 13:44:43 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_two(t_stack_node **a, t_stack_node **b, int *i)
{
	pb(b, a);
	(*i)--;
	if (*i > 3)
	{
		pb(b, a);
		(*i)--;
	}
}

static void	a_sort(t_stack_node **a, t_stack_node **b)
{
	init_nodes(*a, *b);
	sort_a_to_b(a, b);
}

static void	b_sort(t_stack_node **a, t_stack_node **b)
{
	init_nodes_b(*a, *b);
	sort_b_to_a(a, b);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top;
	int				i;

	i = 1;
	top = *a;
	if (!*a || !(*a)->next)
		return ;
	while (top->next != NULL)
	{
		top = top->next;
		i++;
	}
	if (i > 3)
		push_two(a, b, &i);
	while (i > 3)
	{
		a_sort(a, b);
		i--;
	}
	if (i == 3)
		sort_three(a);
	while (*b != NULL)
		b_sort(a, b);
	current_index(*a);
	min_on_top(a);
}

int	stack_sorted(t_stack_node *stack)
{
	t_stack_node	*current;

	if (stack == NULL || stack->next == NULL)
		return (1);
	current = stack;
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}
