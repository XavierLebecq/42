/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:57 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 12:46:04 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	nbr_node(t_stack_node *x)
{
	t_stack_node	*top;
	int				len_node;

	top = x;
	len_node = 0;
	while (top)
	{
		top = top->next;
		len_node++;
	}
	return (len_node);
}

int	find_median(t_stack_node *x)
{
	int	median;
	int	count;

	count = nbr_node(x);
	median = count / 2;
	return (median);
}
