/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 06:21:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/25 10:58:22 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_display(t_var *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_msg("Error initializing MLX\n", NULL);
	game->win = mlx_new_window(game->mlx, game->line_lenght * TILE_SIZE,
			game->map_lines * TILE_SIZE, "So Long");
	if (!game->win)
		ft_error_msg("Error creating window\n", NULL);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "sprites/background.xpm",
			&game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm",
			&game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "sprites/collect.xpm",
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_empty || !game->img_player || !game->img_collect
		|| !game->img_exit || !game->img_wall)
		ft_error_msg("Error loading image\n", game);
	ft_render_map(game);
	mlx_hook(game->win, 2, 1L << 0, ft_handle_key, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close_window, game);
	mlx_loop(game->mlx);
	mlx_destroy_image(game->mlx, game->img);
	ft_cleanup(game);
}

void	ft_render_map(t_var *game)
{
	int x;
	int y;
	void *img;
	
	y = 0;
	while (y < game->map_lines)
	{
		x = 0;
		while (x < game->line_lenght)
		{
			img = NULL;
			if (game->map[y][x] == '1')
				img = game->img_wall;
			else if (game->map[y][x] == 'C')
				img = game->img_collect;
			else if (game->map[y][x] == 'E')
				img = game->img_exit;
			else
				img = game->img_empty;
			mlx_put_image_to_window(game->mlx, game->win, img, x
				* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'P')
			{
				img = game->img_player;
				mlx_put_image_to_window(game->mlx, game->win, img,
					x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	ft_move_player(t_var *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->line_lenght || new_y < 0
		|| new_y >= game->map_lines)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectible_count--;
	if (game->map[new_y][new_x] == 'E' && game->collectible_count == 0)
	{
		ft_cleanup(game);
		exit(0);
	}
	if (game->prev_tile == 'E')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->prev_tile = game->map[new_y][new_x];
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_printf("Nombre de mouvements: %d\n", game->move_count);
	ft_render_map(game);
}

void	ft_find_player_position2(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_lines)
	{
		j = 0;
		while (j < game->line_lenght)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
