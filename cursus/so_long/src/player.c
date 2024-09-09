/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:37:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/25 12:17:58 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_handle_key(int key, t_var *game)
{
	if (key == 65307)
	{
		ft_cleanup(game);
		exit(0);
	}
	else if (key == 'w')
		ft_move_player(game, 0, -1);
	else if (key == 's')
		ft_move_player(game, 0, 1);
	else if (key == 'a')
		ft_move_player(game, -1, 0);
	else if (key == 'd')
		ft_move_player(game, 1, 0);
	return (0);
}

int	ft_close_window(t_var *game)
{
	ft_cleanup(game);
	exit(0);
	return (0);
}
