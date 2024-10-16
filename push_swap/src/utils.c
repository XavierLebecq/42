/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:44:53 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/16 21:52:07 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_check(const char *input_args, char **args_split)
{
	long long result;
	int sign;
	int i;
	int digit;
	
	result = 0;
	sign = 1;
	i = 0;
	while (input_args[i] == ' ' || (input_args[i] >= 9 && input_args[i] <= 13))
		i++;
	if (input_args[i] == '-')
	{
			sign = -1;
			i++;
	} 
	else if (input_args[i] == '+')
		i++;

	if(!ft_isdigit(input_args[i]))
		ft_error_and_exit();
	
	while (input_args[i] && ft_isdigit(input_args[i]))
	{
		digit = input_args[i] - '0';
		
		if((sign == 1 && result > (INT_MAX - digit) / 10) || (sign == -1 && -result < (INT_MIN + digit) / 10))
		{
			ft_free_split_result(args_split);
			ft_error_and_exit();			
		}
		result = result * 10 + digit;
		i++;
	}
	if (input_args[i] != '\0')
		ft_error_and_exit();
	return (int)(result * sign);
}

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
	size_t i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}


int	ft_find_min_value(stack_node *a)
{
	int i;

	i = a->nbr;
	while (a)
	{
		if(i > a->nbr)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_find_max_value(stack_node *a)
{
	int i;

	i = a->nbr;
	while (a)
	{
		if (i < a->nbr)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}
