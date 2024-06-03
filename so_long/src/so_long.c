/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/03 10:04:50 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_var *game)
{
    if (!game->map)
    {
        ft_printf("Error: Map is not loaded.\n");
        return;
    }

    ft_printf("Map content:\n");
    for (int i = 0; i < game->map_lines; i++)
    {
        ft_printf("%s", game->map[i]);
    }
}

size_t	count_lines(t_var *game)
{
	char	*line;
	size_t count = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		free(line);
		line = get_next_line(game->fd);
		count++;
	}
	close (game->fd);
	ft_printf("%d", count);
	return count;
}

int	validate_map(t_var *game)
{
	int exit_count;
	int	player_count;
	int	collectible_count = 0;
	int i;
	int j;

	exit_count = 0;
	player_count = 0;
	collectible_count = 0;
	i = 0;

	while (i < game->map_lines)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				exit_count++;
			else if (game->map[i][j] == 'P')
				player_count++;
			else if (game->map[i][j] == 'C')
				collectible_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1 || player_count != 1 || collectible_count < 1)
	{
		if (exit_count != 1)
			ft_printf("Error: Map must contain exactly one exit.\n");
		if (player_count != 1)
			ft_printf("Error: Map must contain exactly one player.\n");
		if (collectible_count < 1)
			ft_printf("Error: Map must contain at least one collectible.\n");
		return (0);
	}
	return (1);
}

char	**read_map(t_var *game)
{
	char **map;
	char	*line;
	size_t i = 0;

	map = (char **)malloc(sizeof(char *) * (game->map_lines + 1));
	if (!map)
		return (NULL);

	while ((line = get_next_line(game->fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;

	close(game->fd);
	return (map);
}

int main(int argc, char **argv)
{
	
	t_var game;

	
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

	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
	{
		perror("Error opening file");
		exit (EXIT_FAILURE);
	}

	game.map_lines = count_lines(&game);
	if (game.map_lines == 0)
	{
		ft_printf("Error: The map file is empty or could not be read.\n");
		close(game.fd);
		exit(EXIT_FAILURE);
	}

	game.fd = open(argv[1], O_RDONLY);
	game.map = read_map(&game);
	if (!game.map)
	{
		ft_printf("Error: Failed to read the map.\n");
		close (game.fd);
		exit(EXIT_FAILURE);
	}
	print_map(&game);





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
