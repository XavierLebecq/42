/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:04:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 18:04:31 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc < 2)
		exit (EXIT_FAILURE);
	if (argc == 2)
		ft_split_single_arg(&stack.a, argv);
	else
		ft_multi_arg(&stack.a, argc, argv, NULL);
	if (ft_has_duplicates(stack.a))
		ft_free_args_split_stack_exit(NULL, &stack.a, 1);
	if (ft_is_unsorted(stack.a))
		ft_sort_stack(&stack.a, &stack.b);
	ft_free_args_split_stack_exit(NULL, &stack.a, 0);
	return (0);
}

void	ft_split_single_arg(t_stack_node **a, char **argv)
{
	char	**args_split;
	int		i;

	i = 0;
	args_split = ft_split(argv[1], ' ');
	if (!args_split)
		ft_free_args_split_stack_exit(args_split, NULL, 1);
	while (args_split[i])
		ft_atoi_and_push(args_split[i++], args_split, a);
	ft_free_args_split_stack_exit(args_split, NULL, 0);
}

void	ft_multi_arg(t_stack_node **a, int argc, char **argv, char **args_split)
{
	int	i;

	i = 1;
	while (i < argc)
		ft_atoi_and_push(argv[i++], args_split, a);
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
