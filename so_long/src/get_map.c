/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:29 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/04 09:28:45 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t  ft_count_lines(t_var *game)
{
    size_t count = 0;
    game->line = get_next_line(game->fd);
    while (game->line)
    {
        free(game->line);
        game->line = get_next_line(game->fd);
        count++;
    }
    close (game->fd);
    ft_printf("------>%d\n", count);
    return count;
}

char    **read_map(t_var *game)
{
    size_t i = 0;

    game->map = (char **)malloc(sizeof(char *) * (game->map_lines + 1));
    if (!game->map)
        return (NULL);
    game->line = get_next_line(game->fd);
    while (game->line != NULL)
    {
        game->map[i] = game->line;
        game->line = get_next_line(game->fd);
        i++;
    }
    game->map[i] = NULL;

    close(game->fd);
    return (game->map);
}

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
	ft_validate_map(game);
}


