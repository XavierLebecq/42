/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:44:53 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/15 03:10:33 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi_check(char *str)
{
	int	i;
	int sign;
	long long result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if(ft_isdigit(str[i]) == 0)
			ft_error_msg();
		result = result * 10 + str[i] - '0';
		i++;
	}
	result = (sign * result);
	if (result > 2147483647 || result < -2147483648)
		ft_error_msg();
	return (result);
}

void	ft_lstaddback(stack **head, stack *new_node)
{
	if (!head)
		return ;
	if (!*head)
		*head = new_node;
	else
		(ft_lstlast2(*head))->next = new_node;
}

stack	*ft_lstlast2(stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

stack	*ft_stack_new(int content)
{
	stack	*new;

	new = malloc(sizeof (stack));
	if (!new)
		ft_error_msg();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if(!tab)
		return;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_check_double(stack *a)
{
	stack *temp;

	while(a)
	{
		temp = a->next;
		while(temp)
		{
			if(temp->nbr == a->nbr)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_lstsize2(stack *lst)
{
	size_t i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_check_order(stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (1);
		i = a->nbr;
		a = a->next;
	}
	return (0);
}

int	ft_int_min(stack *a)
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

int	ft_int_max(stack *a)
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

void	ft_free_list(stack **lst)
{
	stack *temp;

	if (!lst)
		return;
	temp = NULL;
	while (*lst)
	{
		temp = (*lst)->next;
//		printf("%ld Freeing: %p\n", (*lst)->nbr, (void *)*lst);
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
}
