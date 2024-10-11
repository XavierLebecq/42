/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:11:27 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/11 13:55:36 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_swap **a)
{
	t_swap *temp;

	if (!*a || !((*a)->next))
		return;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	write(1, "sa\n", 3);
}

void	ft_rra(t_swap **a)
{
	t_swap	*temp;
	int	i;

	if (!a || !(*a)->next)
		return;
	i = 0;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_ra(t_swap **a)
{
	if (!*a || !(*a)->next)
		return;

	t_swap	*temp;
	temp = *a;
	*a = ft_lstlast2(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}
void	ft_rr(t_swap **a, t_swap **b)
{
	t_swap *temp;

	if (!a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = ft_lstlast2(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	temp = *b;
	(*b) = ft_lstlast2(*b);
	(*b)->next = temp;
	*b = temp->next;
	write(1, "rr\n", 3);
}
void	ft_rrr(t_swap **a, t_swap **b)
{
	t_swap *temp;
	int	i;
	
	if (!*a || !((*a)->next) || !*b || ! ((*b)->next))
		return ;
	i = 0;
	temp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
}

void	ft_rb(t_swap **b)
{
	t_swap *temp;

	if (!b || !(*b)->next)
		return ;
	temp = *b;
	*b = ft_lstlast2(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	write (1, "rb\n", 3);
}
void	ft_rrb(t_swap **b)
{
	t_swap *temp;
	int	index;

	if (!*b || !(*b)->next)
		return ;
	index = 0;
	temp = *b;
	while ((*b)->next)
	{
		index++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (index > 1)
	{
		temp = temp->next;
		index--;
	}
	temp->next = NULL;
	write(1, "rrb\n", 4);
}


