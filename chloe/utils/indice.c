/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:21 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 12:35:38 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indice(t_stack_node **x)
{
	t_stack_node	*top;
	int				indice;

	top = *x;
	indice = 0;
	while (top)
	{
		top->indice = indice;
		indice++;
		top = top->next;
	}
}

void	current_index(t_stack_node *x)
{
	int	i;
	int	median;

	i = 0;
	if (!x)
		return ;
	median = find_median(x);
	while (x)
	{
		x->indice = i;
		if (i <= median)
			x->median = 1;
		else
			x->median = 0;
		x = x->next;
		++i;
	}
}
