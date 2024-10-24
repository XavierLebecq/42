/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:39:12 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 21:20:19 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_insert_position_b(t_stack_node *b, int insert_value)
{
	int				i;
	t_stack_node	*next_node;

	i = 1;
	if (insert_value > b->nbr && insert_value < ft_stack_last_node(b)->nbr)
		i = 0;
	else if (insert_value > ft_find_max_value(b)
		|| insert_value < ft_find_min_value(b))
		i = ft_find_index_in_stack(b, ft_find_max_value(b));
	else
	{
		next_node = b->next;
		while (insert_value > b->nbr || insert_value < next_node->nbr)
		{
			b = b->next;
			next_node = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_insert_position_a(t_stack_node *a, int insert_value)
{
	int				i;
	t_stack_node	*next_node;

	i = 1;
	if (insert_value < a->nbr && insert_value > ft_stack_last_node(a)->nbr)
		i = 0;
	else if (insert_value > ft_find_max_value(a)
		|| insert_value < ft_find_min_value(a))
		i = ft_find_index_in_stack(a, ft_find_min_value(a));
	else
	{
		next_node = a->next;
		while (insert_value < a->nbr || insert_value > next_node->nbr)
		{
			a = a->next;
			next_node = a->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_index_in_stack(t_stack_node *a, int target_value)
{
	int	i;

	i = 0;
	while (a->nbr != target_value)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	ft_move_min_to_top(t_stack_node **a)
{
	int	i;

	i = ft_find_index_in_stack(*a, ft_find_min_value(*a));
	if (i < ft_stack_size(*a) - i)
	{
		while ((*a)->nbr != ft_find_min_value(*a))
			ft_ra(a);
	}
	else
	{
		while ((*a)->nbr != ft_find_min_value(*a))
			ft_rra(a);
	}
}
