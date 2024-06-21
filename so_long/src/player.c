/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:37:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/21 22:56:03 by xlebecq          ###   ########.fr       */
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
