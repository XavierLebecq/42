/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/03 18:43:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_var *game)
{
	int i;
	int j;

	game->exit_count = 0;
	game->player_count = 0;
	game->collectible_count = 0;
	i = 0;

	while (i < game->map_lines)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'P')
				game->player_count++;
			else if (game->map[i][j] == 'C')
				game->collectible_count++;
			j++;
		}
		i++;
	}
	if (game->exit_count != 1 || game->player_count != 1 || game->collectible_count < 1)
	{
		if (game->exit_count != 1)
		{
			ft_printf("Error: Map must contain exactly one exit.\n");
			exit (EXIT_FAILURE);
		}
		if (game->player_count != 1)
		{
			ft_printf("Error: Map must contain exactly one player.\n");
			exit (EXIT_FAILURE);
		}
		if (game->collectible_count < 1)
		{
			ft_printf("Error: Map must contain at least one collectible.\n");
			exit (EXIT_FAILURE);
		}
		return (0);
	}
	return (1);
}


int main(int argc, char **argv)
{
	t_var game;
	
	ft_check_args(argc, argv, &game);
	validate_map(&game);

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
