/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 06:21:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/13 17:10:53 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int key, t_var *game)
{
	if (key == 65307)
	{
		if (game->img)
			mlx_destroy_image(game->mlx, game->img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}

int	ft_close_window(t_var *game)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	ft_display(t_var *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_msg("Error initializing MLX\n", NULL);
	game->win = mlx_new_window(game->mlx, 1000, 600, "So Long");
	if (!game->win)
		ft_error_msg("Error creating window\n", NULL);
	game->img = mlx_xpm_file_to_image(game->mlx,
			"/home/xlebecq/Documents/42/so_long/herbe.xpm", &game->img_width,
			&game->img_height);
	if (!game->img)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_error_msg("Error loading image\n", NULL);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_hook(game->win, 2, 1L << 0, ft_handle_key, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close_window, game);
	mlx_loop(game->mlx);
	mlx_destroy_image(game->mlx, game->img);
}
