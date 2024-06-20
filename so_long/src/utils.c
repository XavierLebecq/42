/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:28:45 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/13 19:22:13 by xlebecq          ###   ########.fr       */
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
		ft_cleanup(game);
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
void ft_cleanup(t_var *game)
{
    if (game->img)
        mlx_destroy_image(game->mlx, game->img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
        mlx_destroy_display(game->mlx); // Only if using X11 or similar
    free(game->mlx);
    ft_free_map(game); // Assuming this frees the map correctly
}

