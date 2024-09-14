/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:34:53 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 12:57:47 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*cheap_node(t_stack_node *x)
{
	t_stack_node	*cheap;

	if (!x)
		return (NULL);
	cheap = x;
	while (x->next)
	{
		if (x->total_cost < cheap->total_cost)
			cheap = x;
		x = x->next;
	}
	return (cheap);
}
