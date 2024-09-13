/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:11:27 by xlebecq           #+#    #+#             */
/*   Updated: 2024/09/12 19:45:23 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_swap **a, int flag)
{
	t_swap *temp;

	if (!*a || !((*a)->next))
		return;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	ft_rra(t_swap **a, int flag)
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
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	ft_ra(t_swap **a, int flag)
{
	if (!*a || !(*a)->next)
		return;

	t_swap	*temp;
	temp = *a;
	*a = ft_lstlast2(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	if (flag == 0)
		write(1, "ra\n", 3);
}




