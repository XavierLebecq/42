/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:28:45 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 19:34:26 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_whitout_nl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	error_msg(char *msg, t_var *game)
{
	ft_printf("%s", msg);
	if (game != NULL)
		free_map(game);
	exit(EXIT_FAILURE);
}

void	perror_msg(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_map(t_var *game)
{
	int	i;
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	ft_printf("Memory for game->map has been freed.\n");
}

void	init_game(t_var *game)
{
	game->line = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->exit_count = 0;
	game->player_count = 0;
	game->collectible_count = 0;
}
/*void find_player_position(t_var *game)
{
    int i = 0;
    int j = 0;
	int start_x = 0;
	int start_y = 0;
	printf("line_lenght = %d\n", game->line_lenght);
    while (i < game->map_lines)
    {
        j = 0;
        while (j < game->line_lenght)
        {
            if (game->map[i][j] == 'P')
            {
                start_x = i;
				ft_printf ("start_x = %d\n", start_x);
                start_y = j;
				ft_printf ("start_y = %d\n", start_y);
                return;
            }
            j++;
        }
        i++;
    }
}*/