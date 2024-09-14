/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:39:35 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/22 14:10:12 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_node(t_stack_node **a, int n, int i)
{
	t_stack_node	*node;

	if (!a)
		return ;
	node = create_node(n, i);
	if (!node)
		return ;
	add_node_to_end(a, node);
}

t_stack_node	*create_node(int n, int i)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->nbr = n;
	node->cost = 0;
	node->indice = i;
	node->total_cost = 0;
	node->target_node = NULL;
	return (node);
}

void	add_node_to_end(t_stack_node **list, t_stack_node *node)
{
	t_stack_node	*last;

	if (!(*list))
	{
		*list = node;
	}
	else
	{
		last = find_last(*list);
		last->next = node;
		node->prev = last;
	}
}

void	ft_free(char **f)
{
	size_t	i;

	i = 0;
	while (f[i])
	{
		free(f[i]);
		i++;
	}
	free(f);
}
