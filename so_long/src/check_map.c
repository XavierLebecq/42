/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:16:14 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/04 09:29:45 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_map(t_var *game)
{
	int i;
	int j;

	game->exit_count = 0;
	game->player_count = 0;
	game->collectible_count = 0;
	i = 0;

	while (i < game->map_lines)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'P')
				game->player_count++;
			else if (game->map[i][j] == 'C')
				game->collectible_count++;
			j++;
		}
		i++;
	}
	if (game->exit_count != 1 || game->player_count != 1 || game->collectible_count < 1)
	{
		if (game->exit_count != 1)
		{
			ft_printf("Error: Map must contain exactly one exit.\n");
			exit (EXIT_FAILURE);
		}
		if (game->player_count != 1)
		{
			ft_printf("Error: Map must contain exactly one player.\n");
			exit (EXIT_FAILURE);
		}
		if (game->collectible_count < 1)
		{
			ft_printf("Error: Map must contain at least one collectible.\n");
			exit (EXIT_FAILURE);
		}
		return (0);
	}
	return (1);
}
