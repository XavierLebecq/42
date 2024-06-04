/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:58:37 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/04 09:29:30 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "lib.h"
# include <fcntl.h>

typedef struct s_var
{
	int		fd;
	char	*line;
	int		map_lines;
	char	**map;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	void	*mlx;
	void	*win;
	int		exit_count;
	int		player_count;
	int		collectible_count;
}t_var;

int		handle_key(int key);
int		close_window(void);
void	ft_check_args(int argc, char **argv, t_var *game);
void	ft_check_map(char **argv, t_var *game);
char	**read_map(t_var *game);
size_t	ft_count_lines(t_var *game);
void	print_map(t_var *game);
int		ft_validate_map(t_var *game);

#endif
