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

void	ft_split_single_arg(t_stack_node **a, char **argv)
{
	char	**args_split;
	int		i;

	i = 0;
	args_split = ft_split(argv[1], ' ');
	if (!args_split)
		ft_error_and_exit_and_free_all(args_split, a);
	while (args_split[i])
	{
		ft_atoi_and_push(args_split[i], args_split, a);
		i++;
	}
	ft_free_split_result(args_split);
}

void	ft_multi_arg(t_stack_node **a, int argc, char **argv, char **args_split)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_atoi_and_push(argv[i], args_split, a);
		i++;
	}
}
