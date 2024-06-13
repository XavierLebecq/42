/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:29 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 16:38:15 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_lines(char **argv, t_var *game)
{
	game->map_lines = 0;
	game->line = get_next_line(game->fd);
	while (game->line)
	{
		free(game->line);
		game->line = get_next_line(game->fd);
		game->map_lines++;
	}
	close(game->fd);
	if (game->map_lines == 0)
		error_msg("Error: The map file is empty or could not be read.\n", NULL);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		perror_msg("Error opening file");
}

void	read_map(t_var *game)
{
	game->i = -1;
	game->map = (char **)malloc(sizeof(char *) * (game->map_lines + 1));
	if (!game->map)
		error_msg("Error: Memory allocation failed for map.\n", NULL);
	game->line = get_next_line(game->fd);
	while (game->line != NULL)
	{
		game->map[++game->i] = game->line;
		game->line = get_next_line(game->fd);
	}
	game->map[++game->i] = NULL;
	close(game->fd);
}
