/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:19:12 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:24:23 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(stack_node **head, stack_node *new_node)
{
	if (!head || !new_node)
		return ;
	if (!*head)
		*head = new_node;
	else
		(ft_stack_last_node(*head))->next = new_node;
}

stack_node	*ft_stack_last_node(stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

stack_node	*ft_stack_new_node(int content)
{
	stack_node	*new_node;

	new_node = malloc(sizeof (stack_node));
	if (!new_node)
		ft_error_and_exit();
	new_node->nbr = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_stack_size(stack_node *node)
{
	size_t	i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
