/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:36:24 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 14:20:23 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	stack_size(t_stack_node *stack)
{
	int				size;
	t_stack_node	*current;

	size = 0;
	current = stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	top_cost(t_stack_node *x)
{
	t_stack_node	*top;
	int				cost;
	int				mediane;
	int				indice;

	top = x;
	cost = 0;
	mediane = find_median(x);
	indice = 0;
	while (top)
	{
		if (top->indice > mediane)
			break ;
		top->cost = cost;
		cost++;
		indice++;
		top = top->next;
	}
}

void	bot_cost(t_stack_node *x)
{
	t_stack_node	*bot;
	int				cost;
	int				mediane;
	int				indice;

	bot = find_last(x);
	cost = 1;
	indice = stack_size(x) - 1;
	mediane = find_median(x);
	while (bot)
	{
		if (indice <= mediane)
			break ;
		bot->cost = cost;
		cost++;
		indice--;
		bot = bot->prev;
	}
}
