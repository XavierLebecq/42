/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:43:47 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 09:24:08 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_stack(stack_node **node)
{
	stack_node	*next_node;

	if (!node || !*node)
		return ;
	while (*node)
	{
		next_node = (*node)->next;
		free(*node);
		*node = next_node;
	}
}

void	ft_free_split_result(char **args_split)
{
	size_t	i;

	i = 0;
	if (!args_split)
		return ;
	while (args_split[i])
	{
		free(args_split[i]);
		i++;
	}
	free(args_split);
}

int	ft_is_unsorted(stack_node *a)
{
	int	i;

	i = a->nbr;
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_has_duplicates(stack_node *a)
{
	stack_node	*next_node;

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
