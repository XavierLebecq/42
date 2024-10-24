/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:44:53 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 20:27:24 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_and_push(const char *input_args, char **args_split,
			t_stack_node **a)
{
	long long	result;
	int			sign;
	int			i;
	int			digit;

	result = 0;
	sign = 1;
	i = 0;
	ft_handle_sign(input_args, &i, &sign);
	while (input_args[i] && ft_isdigit(input_args[i]))
	{
		digit = input_args[i] - '0';
		if (ft_overflow(result, sign, digit))
			ft_error_and_exit_and_free_all(args_split, a);
		result = result * 10 + digit;
		i++;
	}
	if (input_args[i] != '\0')
		ft_error_and_exit_and_free_all(args_split, a);
	result = ((int)(result * sign));
	ft_stack_add_back(a, ft_stack_new_node(result));
}

int	ft_overflow(long long result, int sign, int digit)
{
	if ((sign == 1 && result > (INT_MAX - digit) / 10)
		|| (sign == -1 && result > (-(INT_MIN + digit)) / 10))
		return (1);
	return (0);
}

void	ft_handle_sign(const char *input_args, int *i, int *sign)
{
	while (input_args[*i] == ' '
		|| (input_args[*i] >= 9 && input_args[*i] <= 13))
		(*i)++;
	if (input_args[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (input_args[*i] == '+')
		(*i)++;
}

int	ft_find_min_value(t_stack_node *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_find_max_value(t_stack_node *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i < a->nbr)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}
