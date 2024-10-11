/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:19 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/10 17:17:10 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_int_three(t_swap **a)
{
	if (ft_int_min(*a) == (*a)->nbr)
	{

		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_int_max(*a) == (*a)->nbr)
	{
		ft_ra(a, 0);
		if (ft_check_order(*a) == 1)
			ft_sa(a, 0);
	}
	else
	{
		if(ft_index_nbr(*a, ft_int_max(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}
		
void	ft_sort(t_swap **a, t_swap **b)
{
	if (ft_lstsize2(*a) == 2)
		ft_sa(a, 0);
	else
	{
		ft_push_b(a, b);
	}
	printf("test sorti de ft_sort\n");
}
void	ft_push_b(t_swap **a, t_swap **b)
{
	if(ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
		ft_pb(a, b, 0);
	if(ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
		ft_pb(a, b, 0);
	if (ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
		ft_sort_more_3(a, b);
	if (ft_check_order(*a) == 1)
		ft_int_three(a);
} 
void	ft_sort_more_3(t_swap **a, t_swap **b)
{
	int	index;
	t_swap *temp;
	printf("a->nbr =%ld\n", (*a)->nbr);
	printf("sizelist=%d\n", ft_lstsize2(*a));
	printf("order=%d\n", ft_check_order(*a));
	while (ft_lstsize2(*a) > 3 && ft_check_order(*a) == 1)
	{
		temp = *a;
		index = ft_cost(*a, *b);
		printf("index =%d\n", index);
		while (index >= 0)
		{
			if (index == ft_cost_rarb(*a, *b, temp->nbr))
				index = 1;
			else if (index == ft_cost_rrarrb(*a, *b, temp->nbr))
				index = 2;
			else if (index == ft_cost_rarrb(*a, *b, temp->nbr))
				index = 3;
			else if (index == ft_cost_rrarb(*a, *b, temp->nbr))
				index = 4;
			else
				temp = temp->next;
		}
	}

}
int	ft_cost(t_swap *a, t_swap *b)
{
	int index;
	t_swap	*temp;
	
	temp = a;
	index = ft_cost_rrarrb(a, b, a->nbr); 
	while (temp)
	{
		printf("temp->nbr =%ld\n", temp->nbr);
		if (index > ft_cost_rarb(a, b, temp->nbr))
			index = ft_cost_rarb(a, b, temp->nbr);
		if (index > ft_cost_rrarrb(a, b, temp->nbr))
			index = ft_cost_rrarrb(a, b, temp->nbr);
		if	(index > ft_cost_rrarb(a, b, temp->nbr))
			index = ft_cost_rrarb(a, b, temp->nbr);
		temp = temp->next;
	}
	return (index);
}