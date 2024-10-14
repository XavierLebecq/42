/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:19 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/14 20:51:00 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 5 1 2 3 4 6 43 98 23 888888 22222 3333 1111

void	ft_sort(t_swap **a, t_swap **b)
{
	int	index;
	
	if (ft_lstsize2(*a) == 2)
		ft_sa(a);
	else
	{
		ft_push_b(a, b);
		ft_push_a(a, b);
		index = ft_position(*a, ft_int_min(*a));
		if (index < ft_lstsize2(*a) - index)
		{
			while ((*a)->nbr != ft_int_min(*a))
				ft_ra(a);
		}
		else
		{
			while ((*a)->nbr != ft_int_min(*a))
				ft_rra(a);
		}
	}
	printf("test sorti de ft_sort\n");
}

void	ft_push_b(t_swap **a, t_swap **b)
{
	if(ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
		ft_pb(a, b);
	if(ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
		ft_pb(a, b);
	if (ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
		ft_sort_more_3(a, b);
	if (ft_check_order(*a) == 1)
		ft_int_three(a);
}

void	ft_sort_more_3(t_swap **a, t_swap **b)
{
	int	index;
	t_swap *temp;
	printf("a->nbr = %ld\n", (*a)->nbr);
	printf("sizelist = %d\n", ft_lstsize2(*a));
	printf("check_order = %d\n", ft_check_order(*a));
	while (ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
	{
		temp = *a;
		index = ft_cost_b(*a, *b);
		while (index >= 0)
		{
			printf("cost_rarb = %d\n", ft_cost_rarb_b(*a, *b, temp->nbr));
			if (index == ft_cost_rarb_b(*a, *b, temp->nbr))
				index = ft_apply_rarb_b(a, b, temp->nbr);
			else if (index == ft_cost_rrarrb_b(*a, *b, temp->nbr))
				index = ft_apply_rrarrb_b(a, b, temp->nbr);
			else if (index == ft_cost_rarrb_b(*a, *b, temp->nbr))
				index = ft_apply_rarrb_b(a, b, temp->nbr);
			else if (index == ft_cost_rrarb_b(*a, *b, temp->nbr))
				index = ft_apply_rrarb_b(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
}

int	ft_cost_b(t_swap *a, t_swap *b)
{
	int index;
	t_swap	*temp;
	
	temp = a;
	index = ft_cost_rrarrb_b(a, b, a->nbr);
	printf("rrarrb index = %d\n", index); 
	while (temp)
	{
		printf("temp->nbr =%ld\n", temp->nbr);
		if (index > ft_cost_rarb_b(a, b, temp->nbr))
			index = ft_cost_rarb_b(a, b, temp->nbr);
		if (index > ft_cost_rrarrb_b(a, b, temp->nbr))
			index = ft_cost_rrarrb_b(a, b, temp->nbr);
		if	(index > ft_cost_rrarb_b(a, b, temp->nbr))
			index = ft_cost_rrarb_b(a, b, temp->nbr);
		temp = temp->next;
	}
	printf("ft_cost index = %d\n", index);
	return (index);
}

void	ft_push_a(t_swap **a, t_swap **b)
{
	int	index;
	t_swap	*temp;

	while (*b)
	{
		temp = *b;
		index = ft_cost_a(*a, *b);
		while (index >= 0)
		{
			if (index == ft_cost_rarb_a(*a, *b, temp->nbr))
				index = ft_apply_rarb_a(a, b, temp->nbr);
			else if (index == ft_cost_rarrb_a(*a, *b, temp->nbr))
				index = ft_apply_rarrb_a(a, b, temp->nbr);
			else if (index == ft_cost_rrarrb_a(*a, *b, temp->nbr))
				index = ft_apply_rrarrb_a(a, b, temp->nbr);
			else if (index == ft_cost_rrarb_a(*a, *b, temp->nbr))
				index = ft_apply_rrarb_a(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
}

int	ft_cost_a(t_swap *a, t_swap *b)
{
	int index;
	t_swap	*temp;

	temp = 0;
	index = ft_cost_rrarrb_a(a, b, b->nbr);
	while (temp)
	{
		if (index > ft_cost_rarb_a(a, b, temp->nbr))
			index = ft_cost_rarb_a(a, b, temp->nbr);
		if (index > ft_cost_rrarrb_a(a, b, temp->nbr))
			index = ft_cost_rrarrb_a(a, b, temp->nbr);
		if (index > ft_cost_rarrb_a(a, b, temp->nbr))
			index = ft_cost_rarrb_a(a, b, temp->nbr);
		if (index > ft_cost_rrarb_a(a, b, temp->nbr))
			index = ft_cost_rrarb_a(a, b, temp->nbr);
		temp = temp->next;

	}
	return (index);
}

void	ft_int_three(t_swap **a)
{
	if (ft_int_min(*a) == (*a)->nbr)
	{

		ft_rra(a);
		ft_sa(a);
	}
	else if (ft_int_max(*a) == (*a)->nbr)
	{
		ft_ra(a);
		if (ft_check_order(*a) == 1)
			ft_sa(a);
	}
	else
	{
		if(ft_position(*a, ft_int_max(*a)) == 1)
			ft_rra(a);
		else
			ft_sa(a);
	}
}