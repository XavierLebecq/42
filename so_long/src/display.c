/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 06:21:32 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/10 06:32:55 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display(t_var *game)
{
	void *img;
	int img_width;
	int img_height;

    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 1000, 600, "So Long");

	img = mlx_xpm_file_to_image(game->mlx, "/home/xlebecq/Documents/42/so_long/herbe.xpm", &img_width, &img_height);

	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);

	mlx_hook(game->win, 2, 1L << 0, handle_key, NULL);
	mlx_hook(game->win, 17, 1L << 17, close_window, NULL);

    mlx_loop(game->mlx);
}
