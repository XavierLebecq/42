/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:28:45 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 01:50:45 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_whitout_nl(const char *s, t_var *game)
{
	game->i = 0;
	while (s[game->i] && s[game->i] != '\n')
		game->i++;
	return (game->i);
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
	game->i = 0;
	while (game->map[game->i])
	{
		free(game->map[game->i]);
		game->i++;
	}
	free(game->map);
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
