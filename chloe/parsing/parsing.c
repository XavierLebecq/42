/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:07 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/23 19:32:16 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 1;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int	parsing_arg(int argc, char **argv)
{
	int		i;
	char	**split_args;
	int		new_argc;

	i = 1;
	new_argc = 0;
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			return (-1);
		while (split_args[i])
			i++;
		i = 1;
		while (split_args[i] != NULL)
			i++;
		new_argc = i;
		ft_errors_split(new_argc, split_args);
		free_split(split_args);
	}
	else
		return (-1);
	return (0);
}

int	parsing_quote(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
