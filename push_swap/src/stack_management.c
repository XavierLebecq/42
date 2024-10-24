/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:43:47 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:30:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_args_split_stack_exit(char **args_split, t_stack_node **a, int exit_flag)
{
	t_stack_node	*next_node;
	size_t			i;

	i = 0;
	if (a && *a)
	{
		while (*a)
		{
			next_node = (*a)->next;
			free(*a);
			*a = next_node;
		}
	}
	if (args_split)
	{
		while (args_split[i])
		{
			free(args_split[i]);
			i++;
		}
		free(args_split);
	}
	if (exit_flag == 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	ft_is_unsorted(t_stack_node *a)
{
	int	i;

	i = a->nbr;
	while (a && a->nbr)
	{
		if (i > a->nbr)
			return (1);
		i = a->nbr;
		a = a->next;
	}
	return (0);
}

int	ft_has_duplicates(t_stack_node *a)
{
	t_stack_node	*next_node;

	while (a)
	{
		next_node = a->next;
		while (next_node)
		{
			if (next_node->nbr == a->nbr)
				return (1);
			next_node = next_node->next;
		}
		a = a->next;
	}
	return (0);
}
