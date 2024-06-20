/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:24:10 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/20 23:29:35 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path(t_var *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	game->visited = (char **)malloc((game->map_lines + 1) * sizeof(char *));
	if (!game->visited)
		free(game->visited);
	while (i < game->map_lines)
	{
		game->visited[i] = (char *)malloc(game->line_lenght * sizeof(char));
		if (!game->visited[i])
		{
			free(game->visited[i]);
			free(game->visited);
			ft_error_msg("Error: Memory allocation failed\n", game);
		}
		j = 0;
		while (j < game->line_lenght)
		{
			game->visited[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_find_player_position(game, &game->start_x, &game->start_y);
	ft_flood_fill(game, game->start_x, game->start_y, game->visited);
	game->exit_found = 0;
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

void	ft_find_player_position(t_var *game, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_lines)
	{
		j = 0;
		while (j < game->line_lenght)
		{
			if (game->map[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_is_valid_position(t_var *game, int x, int y, char **visited)
{
	return (x > 0 && x < game->map_lines && y >= 0 && y < game->line_lenght
		&& game->map[x][y] != '1' && !visited[x][y]);
}
