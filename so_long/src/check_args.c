/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:20:19 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/03 18:28:28 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "lib.h"

void	ft_check_args(int argc, char **argv, t_var *game)
{
	if (argc != 2)
	{
		ft_printf ("Error: invalid number of arguments. Usage: ./so_long <map_file.ber>\n");
		exit (EXIT_FAILURE);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1])-4], ".ber", 4) != 0)
	{
		ft_printf ("Error: invalid map file extension. Expected a '.ber' file.\n");
		exit (EXIT_FAILURE);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		perror("Error opening file");
		exit (EXIT_FAILURE);
	}
	ft_check_map(argv, game);
}

void	ft_check_map(char **argv, t_var *game)
{
	game->map_lines = ft_count_lines(game);
	if (game->map_lines == 0)
    {
        ft_printf("Error: The map file is empty or could not be read.\n");
        close(game->fd);
        exit(EXIT_FAILURE);
    }
    game->fd = open(argv[1], O_RDONLY);
    game->map = read_map(game);
    if (!game->map)
    {
        ft_printf("Error: Failed to read the map.\n");
        close (game->fd);
        exit(EXIT_FAILURE);
    }
    print_map(game);
}

