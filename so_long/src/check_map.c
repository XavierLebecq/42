/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:16:14 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 01:51:04 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_map(t_var *game)
{
	game->i = -1;
	while (++game->i < game->map_lines)
	{
		game->j = 0;
		while (game->map[game->i][game->j] != '\0')
		{
			if (game->map[game->i][game->j] == 'E')
				game->exit_count++;
			else if (game->map[game->i][game->j] == 'P')
				game->player_count++;
			else if (game->map[game->i][game->j] == 'C')
				game->collectible_count++;
			game->j++;
		}
	}
	ft_print_msg(game);
}

void	ft_print_msg(t_var *game)
{
	if (game->exit_count != 1 || game->player_count != 1
		|| game->collectible_count < 1)
	{
		if (game->exit_count != 1)
			error_msg("Error: Map must contain exactly one exit.\n", game);
		if (game->player_count != 1)
			error_msg("Error: Map must contain exactly one player.\n", game);
		if (game->collectible_count < 1)
			error_msg("Error: Map must contain at least one collectible.\n",
				game);
	}
}

void	ft_check_map(t_var *game)
{
	if (!ft_is_rectangular(game))
		error_msg("Error: The map is not rectangular. \n", game);
	if (!ft_is_surrounded_by_walls(game))
		error_msg("Error: The map is not surrounded by walls. \n", game);
}

int	ft_is_rectangular(t_var *game)
{
	if (game->map_lines < 1)
		return (0);
	game->line_lenght = ft_strlen_whitout_nl(game->map[0], game);
	game->i = 0;
	while (++game->i < game->map_lines)
		if (ft_strlen_whitout_nl(game->map[game->i], game) != game->line_lenght)
			return (0);
	return (1);
}

int	ft_is_surrounded_by_walls(t_var *game)
{
	game->i = -1;
	while (game->map[0][++game->i] && game->map[0][game->i] != '\n')
	{
		if (game->map[0][game->i] != '1')
			return (0);
	}
	game->i = -1;
	while (game->map[game->map_lines - 1][++game->i])
	{
		if (game->map[game->map_lines - 1][game->i] != '1')
			return (0);
	}
	game->j = 0;
	while (++game->j < game->map_lines - 1)
	{
		if (game->map[game->j][0] != '1'
			|| game->map[game->j][ft_strlen_whitout_nl(game->map[game->j], game)
			- 1] != '1')
			return (0);
	}
	return (1);
}
