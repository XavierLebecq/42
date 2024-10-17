/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:44:53 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 09:37:53 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_check(const char *input_args, char **args_split)
{
	long long	result;
	int			sign;
	int			i;
	int			digit;

	result = 0;
	sign = 1;
	i = 0;
	ft_handle_sign(input_args, &i, &sign);
	if (!ft_isdigit(input_args[i]))
		ft_error_and_exit();
	while (input_args[i] && ft_isdigit(input_args[i]))
	{
		digit = input_args[i] - '0';
		ft_overflow(result, sign, digit, args_split);
		result = result * 10 + digit;
		i++;
	}
	if (input_args[i] != '\0')
		ft_error_and_exit();
	return ((int)(result * sign));
}

void	ft_overflow(long long result, int sign, int digit, char **args_split)
{
	if ((sign == 1 && result > (INT_MAX - digit) / 10)
		|| (sign == -1 && - result < (INT_MIN + digit) / 10))
	{
		ft_free_split_result(args_split);
		ft_error_and_exit();
	}		
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

int	ft_find_min_value(stack_node *a)
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

int	ft_find_max_value(stack_node *a)
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
