/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:04:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 09:11:19 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stacks	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc < 2)
		exit (1);
	if (argc == 2)
		ft_split_single_arg(&stack.a, argv);
	else
		ft_multi_arg(&stack.a, argc, argv, NULL);
	if (ft_has_duplicates(stack.a) || !stack.a)
	{
		ft_free_stack(&stack.a);
		ft_error_and_exit();
	}
	if (ft_is_unsorted(stack.a))
		ft_sort_stack(&stack.a, &stack.b);
	ft_free_stack(&stack.a);
	return (0);
}

void	ft_split_single_arg(stack_node **a, char **argv)
{
	char	**args_split;
	int		i;
	int		nbr;

	i = 0;
	args_split = ft_split(argv[1], ' ');
	if (!args_split)
		ft_error_and_exit();
	while (args_split[i])
	{
		nbr = ft_atoi_check(args_split[i], args_split);
		ft_stack_add_back(a, ft_stack_new_node(nbr));
		i++;
	}
	ft_free_split_result(args_split);
}

void	ft_multi_arg(stack_node **a, int argc, char **argv, char **args_split)
{
	int	i;
	int	nbr;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi_check(argv[i], args_split);
		ft_stack_add_back(a, ft_stack_new_node(nbr));
		i++;
	}
}
