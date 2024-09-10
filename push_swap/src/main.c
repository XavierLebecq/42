/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:04:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/09/09 23:17:06 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_error_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}



t_swap	*ft_stack_new(int content)
{
	t_swap	*new;

	new = malloc(sizeof (t_swap));
	if (!new)
		ft_error_msg();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

t_swap	*ft_lstlast2(t_swap *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddback(t_swap **stack, t_swap *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast2(*stack))->next = stack_new;
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
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_error_msg();
	return (result * sign);
}


void	ft_single_arg(char **argv)
{
	t_swap *a;
	char **tab;
	int	i;
	int arg;

	i = 0;
	arg = 0;
	a = NULL;
	tab = ft_split(argv[1], ' ');
	if(!tab)
		ft_error_msg();
	while(tab[i])
	{
		arg = ft_atoi_check(tab[i]);
		ft_lstaddback(&a, ft_stack_new(arg));
		i++;
	}
	free(tab);
}

void	init_list(int argc, char **argv)
{
	if (argc < 2)
		ft_error_msg();
	if (argc == 2)
		ft_single_arg(argv);
}

	
int main(int argc, char **argv)
{
	init_list(argc, argv);
}
