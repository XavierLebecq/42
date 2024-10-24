/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:19:12 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 10:30:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack_node **head, t_stack_node *new_node)
{
	if (!head || !new_node)
		return ;
	if (!*head)
		*head = new_node;
	else
		(ft_stack_last_node(*head))->next = new_node;
}

t_stack_node	*ft_stack_last_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack_node	*ft_stack_new_node(int content)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof (t_stack_node));
	if (!new_node)
		ft_free_args_split_stack_exit(NULL, &new_node, 1);
	new_node->nbr = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_stack_size(t_stack_node *node)
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
