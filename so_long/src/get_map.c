/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:29 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/25 10:13:02 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_lines(char **argv, t_var *game)
{
	game->line = get_next_line(game->fd);
	while (game->line)
	{
		if (ft_strlen(game->line) > 1)
			game->map_lines++;
		else
			game->emptyline = 1;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	close(game->fd);
	if (game->emptyline == 1)
		ft_error_msg("Error: The map contains empty lines inside the map.\n",
			NULL);
	if (game->map_lines == 0)
		ft_error_msg("Error: The map file is empty or could not be read.\n",
			NULL);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		ft_perror_msg("Error opening file");
}

void	ft_read_map(t_var *game)
{
	int	index;
	int	found_non_empty_line;

	index = 0;
	found_non_empty_line = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_lines + 1));
	if (!game->map)
		ft_error_msg("Error: Memory allocation failed for map.\n", NULL);
	game->line = get_next_line(game->fd);
	while (game->line)
	{
		if (ft_strlen(game->line) > 1)
		{
			game->map[index] = game->line;
			index++;
		}
		else
		{
			free(game->line);
		}
		game->line = get_next_line(game->fd);
	}
	game->map[index] = NULL;
	game->line_lenght = ft_strlen_whitout_nl(game->map[0]);
	close(game->fd);
}
