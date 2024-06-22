/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:16:14 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/22 10:57:17 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_map(t_var *game)
{
	game->i = -1;
	while (++game->i < game->map_lines)
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			game->current_char = game->map[game->i][game->j];
			if (!ft_strchr(game->valid_chars, game->current_char))
				ft_error_msg("Error: Invalid character in the map.\n", game);
			if (game->current_char == 'E')
				game->exit_count++;
			else if (game->current_char == 'P')
				game->player_count++;
			else if (game->current_char == 'C')
				game->collectible_count++;
			game->j++;
		}
	}
	if (game->exit_count != 1)
		ft_error_msg("Error: Map must contain exactly one exit.\n", game);
	if (game->player_count != 1)
		ft_error_msg("Error: Map must contain exactly one player.\n", game);
	if (game->collectible_count < 1)
		ft_error_msg("Error: Map must contain at least one collectible.\n",
			game);
}

int	ft_is_rectangular(t_var *game)
{
	if (game->map_lines < 1)
		return (0);
	game->i = 0;
	while (game->i < game->map_lines)
	{
		if (ft_strlen_whitout_nl(game->map[game->i]) != game->line_lenght)
			ft_error_msg("Error: The map is not rectangular. \n", game);
		game->i++;
//		ft_printf ("\nmaplines -> %d\n", game->map_lines);
	}
	return (1);
}

void	ft_is_surrounded_by_walls(t_var *game)
{
	game->i = -1;
	while (game->map[0][++game->i] && game->map[0][game->i] != '\n')
	{
		if (game->map[0][game->i] != '1')
			ft_error_msg("Error: The map is not surrounded by walls. \n", game);
	}
	game->i = -1;
	while (game->map[game->map_lines - 1][++game->i] &&
		game->map[game->map_lines - 1][game->i] != '\n')
	{
		if (game->map[game->map_lines - 1][game->i] != '1')
			ft_error_msg("Error: The map is not surrounded by walls. \n", game);
	}
	game->j = 0;
	while (++game->j < game->map_lines - 1)
	{
		if (game->map[game->j][0] != '1'
			|| game->map[game->j][ft_strlen_whitout_nl(game->map[game->j])
			- 1] != '1')
			ft_error_msg("Error: The map is not surrounded by walls. \n", game);
	}
}
