/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:24:10 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/24 23:47:17 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path(t_var *game)
{
	game->i = 0;
	game->j = 0;
	game->visited = (char **)malloc((game->map_lines + 1) * sizeof(char *));
	if (!game->visited)
		free(game->visited);
	while (game->i < game->map_lines)
	{
		game->visited[game->i] = (char *)malloc(
				game->line_lenght * sizeof(char));
		if (!game->visited[game->i])
		{
			free(game->visited[game->i]);
			free(game->visited);
			ft_error_msg("Error: Memory allocation failed\n", game);
		}
		game->j = 0;
		while (game->j < game->line_lenght)
		{
			game->visited[game->i][game->j] = 0;
			game->j++;
		}
		game->i++;
	}
	ft_check_exit(game);
}

void	ft_check_exit(t_var *game)
{
	int	i;
	int	j;

	ft_find_player_position(game, &game->start_x, &game->start_y);
	ft_flood_fill(game, game->start_x, game->start_y, game->visited);
	game->exit_found = 0;
	game->collectible_found = 0;
	
	i = 0;
	while (i < game->map_lines)
	{
		j = 0;
		while (j < game->line_lenght)
		{
			if (game->map[i][j] == 'E' && game->visited[i][j])
			{
				game->exit_found = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_exit(game);
}

void	ft_exit(t_var *game)
{
	int	i;

	if (!game->exit_found)
	{	
		i = 0;
		while (i < game->map_lines)
		{
			free(game->visited[i]);
			i++;
		}
		free(game->visited);
		ft_error_msg("Error : No valid path to the exit.\n", game);
	}
	i = 0;
	while (i < game->map_lines)
	{
		free(game->visited[i]);
		i++;
	}
	free(game->visited);
}

void	ft_flood_fill(t_var *game, int x, int y, char **visited)
{
	if (!ft_is_valid_position(game, x, y, visited))
		return ;
	visited[x][y] = 1;
	ft_flood_fill(game, x - 1, y, visited);
	ft_flood_fill(game, x + 1, y, visited);
	ft_flood_fill(game, x, y - 1, visited);
	ft_flood_fill(game, x, y + 1, visited);
}
