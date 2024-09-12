/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:19 by xlebecq           #+#    #+#             */
/*   Updated: 2024/09/12 20:07:22 by xlebecq          ###   ########.fr       */
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
		
void	ft_sort(t_swap **a)
{
	if (ft_lstsize2(*a) == 2)
		ft_sa(a, 0);
	else if (ft_lstsize2(*a) == 3)
		ft_int_three(a);
}
