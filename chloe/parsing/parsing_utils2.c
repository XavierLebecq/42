/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:31:53 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/23 19:33:37 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_errors(int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	if (check_digit(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (check_double(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (z_overflow(argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (check_sign(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (0);
}

int	ft_errors_split2(int argc, char **split)
{
	if (z_overflow(split) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		free_split(split);
		exit(1);
	}
	if (check_sign(argc, split) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		free_split(split);
		exit(1);
	}
	return (0);
}

int	ft_errors_split(int argc, char **split)
{
	if (argc < 2)
	{
		free_split(split);
		exit(1);
	}
	if (check_digit(argc, split) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		free_split(split);
		exit(1);
	}
	if (check_double(argc, split) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		free_split(split);
		exit(1);
	}
	ft_errors_split2(argc, split);
	return (0);
}
