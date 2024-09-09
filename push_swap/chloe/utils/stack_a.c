/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:09:43 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/23 15:00:47 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		add_node(a, (int)n, i - 1);
		i++;
	}
}

void	init_stack_a_to(t_stack_node **a, char **argv)
{
	long	n;
	int		i;
	char	**split_args;

	i = 0;
	n = 0;
	split_args = ft_split(argv[1], ' ');
	i++;
	while (split_args[i] != NULL)
	{
		n = ft_atoi(split_args[i]);
		add_node(a, (int)n, i - 1);
		i++;
	}
	free_split(split_args);
}
