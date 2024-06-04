/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/04 09:30:05 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_var game;
	
	ft_check_args(argc, argv, &game);

	void *img;
	int img_width;
	int img_height;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 1000, 600, "So Long");

	img = mlx_xpm_file_to_image(game.mlx, "/home/xlebecq/Documents/42/so_long/herbe.xpm", &img_width, &img_height);

	mlx_put_image_to_window(game.mlx, game.win, img, 0, 0);

	mlx_hook(game.win, 2, 1L << 0, handle_key, NULL);
	mlx_hook(game.win, 17, 1L << 17, close_window, NULL);

    mlx_loop(game.mlx);


    return 0;
}
