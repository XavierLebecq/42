/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:24:10 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 19:42:04 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_position(t_var *game, int x,int y, char **visited)
{
    return (x > 0 && x < game->map_lines && y >= 0 && y < game->line_lenght &&
            game->map[x][y] != '1' && !visited[x][y]); 
}

void    flood_fill(t_var *game, int x, int y, char **visited)
{
    if (!is_valid_position(game, x, y, visited))
        return;

    visited[x][y] = 1;
    flood_fill(game, x - 1, y, visited);
    flood_fill(game, x + 1, y, visited);
    flood_fill(game, x, y - 1, visited);
    flood_fill(game, x, y + 1, visited);
}

void find_player_position(t_var *game, int *start_x, int *start_y)
{
    int i = 0;
    int j = 0;

    while (i < game->map_lines)
    {
        j = 0;
        while (j < game->line_lenght)
        {
            if (game->map[i][j] == 'P')
            {
                *start_x = i;
                *start_y = j;
                return;
            }
            j++;
        }
        i++;
    }
}

void check_path(t_var *game)
{
    char **visited;
    int start_x, start_y;
    int i = 0;
    int j = 0;
    
    visited = (char **)malloc((game->map_lines + 1) * sizeof(char *));
    while (i < game->map_lines)
    {
        visited[i] = (char *)malloc(game->line_lenght * sizeof(char));
        j = 0;
        while (j < game->line_lenght)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    find_player_position(game, &start_x, &start_y);
    flood_fill(game, start_x, start_y, visited);

    int exit_found = 0;
    i = 0;
    while (i < game->map_lines)
    {
        j = 0;
        while (j < game->line_lenght)
        {
            if (game->map[i][j] == 'E' && visited[i][j])
            {
                exit_found = 1;
                break;
            }
            j++;
        }
        i++;
    }
    
    if (!exit_found)
        error_msg("Error : No valid path to the exit.\n", game);
    i = 0;
    while(i < game->map_lines)
    {
        free(visited[i]);
            i++;
    }
    free(visited);
}
