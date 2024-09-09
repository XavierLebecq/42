/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:41 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/30 14:09:18 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if (!(j == 0 && (argv[i][j] == '-' || argv[i][j] == '+')))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	if (ft_strncmp(argv[1], "-2147483648", 12) == 0)
		return (0);
	if (argc >= 2)
		ft_atoi(argv[1]);
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	z_overflow(char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num < INTMIN || num > INTMAX)
			return (-1);
		i++;
	}
	return (0);
}

int	check_sign(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (strlen(argv[i]) == 1 && (argv[i][0] == '+' || argv[i][0] == '-'))
			return (-1);
		i++;
	}
	return (0);
}
