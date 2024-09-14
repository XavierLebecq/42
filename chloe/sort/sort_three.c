/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:50:30 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 12:50:34 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
	{
		ra(a);
	}
	else if ((*a)->next && (*a)->next == biggest_node)
	{
		rra(a);
	}
	if (((*a) && (*a)->next) && (*a)->nbr > (*a)->next->nbr)
	{
		sa(a);
	}
}
