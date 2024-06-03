/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:58:37 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/03 08:55:41 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "lib.h"
# include <fcntl.h>

typedef struct s_var
{
	int	fd;
	char *line;
	int	map_lines;
	char **map;
	int	player_x;
	int player_y;
	int moves;
	int collectibles;
	void *mlx;
	void *win;
}t_var;

int handle_key(int key);
int close_window(void);

#endif

