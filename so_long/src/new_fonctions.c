/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:28:45 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/13 17:13:21 by xlebecq          ###   ########.fr       */
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

void	ft_error_msg(char *msg, t_var *game)
{
	ft_printf("%s", msg);
	if (game != NULL)
		ft_free_map(game);
	exit(EXIT_FAILURE);
}

void	ft_perror_msg(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_free_map(t_var *game)
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
}

void	ft_init_game(t_var *game)
{
	game->line = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->exit_count = 0;
	game->player_count = 0;
	game->collectible_count = 0;
	game->line_lenght = 0;
	game->i = 0;
	game->j = 0;
	game->fd = 0;
	game->map_lines = 0;
	game->valid_chars = "10CPE\n";
}
