/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:20:19 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/25 11:43:29 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_var *game)
{
	game->line = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->img_empty = NULL;
	game->img_collect = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_wall = NULL;
	game->exit_count = 0;
	game->player_count = 0;
	game->collectible_count = 0;
	game->line_lenght = 0;
	game->i = 0;
	game->j = 0;
	game->fd = 0;
	game->map_lines = 0;
	game->valid_chars = "10CPE\n";
	game->exit_found = 0;
	game->prev_tile = '0';
	game->move_count = 0;
	game->emptyline = 0;
	game->x = -1;
	game->y = 0;
}

void	ft_check_args(int argc, char **argv, t_var *game)
{
	if (argc != 2)
		ft_error_msg("Error: invalid number of arguments.\n", NULL);
	if (ft_strlen(argv[1]) == 4 && ft_strncmp(argv[1], ".ber", 4) == 0)
		ft_error_msg(
			"Error: invalid file name. The file name cannot be just '.ber'.\n",
			NULL);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		ft_error_msg("Error: invalid file extension. Expected a '.ber' file.\n",
			NULL);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		ft_perror_msg("Error opening file");
}

void	ft_cleanup_exit(t_var *game)
{
	ft_cleanup(game);
	exit(EXIT_FAILURE);
}

void	ft_hook(t_var *game)
{
	mlx_hook(game->win, 2, 1L << 0, ft_handle_key, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close_window, game);
}
