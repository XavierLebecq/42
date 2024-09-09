/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:54:00 by cschmid           #+#    #+#             */
/*   Updated: 2024/06/03 10:01:40 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// static void	print_stack(t_stack_node *a)
// {
// 	printf("--------stack a----------\n");
// 	while (a)
// 	{
// 		printf("%d\n", a->nbr);
// 		a = a->next;
// 	}
// }

static void	sort(t_stack_node **a, t_stack_node **b)
{
	if (!(stack_sorted(*a) == 1))
	{
		if (count_stack(*a) == 2)
			sa(a);
		else if (count_stack(*a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
}

void	arg(int argc, char **argv)
{
	parsing_quote(argc, argv);
	ft_errors(argc, argv);
}

void	sort_clean(t_stack_node **a, t_stack_node **b)
{
	sort(a, b);
	free_all(a, b);
}

void	initialize_stacks(int argc, char **argv, t_stack_node ***a,
		t_stack_node ***b)
{
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		parsing_arg(argc, argv);
		*a = malloc(sizeof(t_stack_node *));
		if (!(*a))
			exit(-1);
		**a = NULL;
		init_stack_a_to(*a, argv);
	}
	else if (argc > 2)
	{
		arg(argc, argv);
		*a = malloc(sizeof(t_stack_node *));
		if (!(*a))
			exit(-1);
		**a = NULL;
		init_stack_a(*a, argv);
	}
	*b = malloc(sizeof(t_stack_node *));
	if (!(*b))
		exit(-1);
	**b = NULL;
}

int	main(int argc, char **argv)
{
	t_stack_node	**a;
	t_stack_node	**b;

	initialize_stacks(argc, argv, &a, &b);
	sort_clean(a, b);
	return (0);
}
