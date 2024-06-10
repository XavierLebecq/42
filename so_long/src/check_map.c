/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:16:14 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/10 11:34:38 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

int	ft_is_rectangular(t_var *game)
{
	int	i;
	size_t line_lenght;
	printf("map_lines-%d\n", game->map_lines);
	if (game->map_lines < 1)
		return (0);

	line_lenght = ft_strlen_whitout_nl(game->map[0]);
	printf ("line lenght--->%zu\n", line_lenght);
	printf ("ft_strlen(game_map[0])--->%zu\n", ft_strlen_whitout_nl(game->map[9]));
	
	i = 1;

	while (i < game->map_lines)
	{
	
		printf ("i -%d-\n", i);
		if (ft_strlen_whitout_nl(game->map[i]) != line_lenght)
		{
			printf ("-map%zu-", ft_strlen_whitout_nl(game->map[i]));
			printf ("-line%zu-", line_lenght);
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int	ft_is_surrounded_by_walls(t_var *game)
{
	int i;
	
	i = 0;
	ft_printf("%s, game->map_lines")
	i = 0;
	while (game->map[game->map_lines - 1][i])
	{
		if (game->map[game->map_lines - 1][i] != '1')
			return (0);
		i++;
	}	
	return (1);

}
*/
