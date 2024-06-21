/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:58:37 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/21 23:36:32 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define TILE_SIZE 64

typedef struct s_var
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	int		map_lines;
	char	**map;
	int		exit_count;
	int		player_count;
	int		collectible_count;
	int		line_lenght;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_empty;
	int		img_width;
	int		img_height;
	char	current_char;
	const char *valid_chars;
	int		start_x;
	int		start_y;
	char	**visited;
	int		exit_found;
}			t_var;

void		ft_exit(t_var *game);
void 		ft_check_exit(t_var *game);
int			ft_handle_key(int key, t_var *game);
int			ft_close_window(t_var *game);
void		ft_check_args(int argc, char **argv, t_var *game);
void		ft_check_map(t_var *game);
void		ft_read_map(t_var *game);
void		ft_count_lines(char **argv, t_var *game);
void		ft_validate_map(t_var *game);
void		ft_display(t_var *game);
int			ft_is_rectangular(t_var *game);
void		ft_is_surrounded_by_walls(t_var *game);
int			ft_strlen_whitout_nl(const char *s);
void		ft_error_msg(char *msg, t_var *game);
void		ft_perror_msg(char *msg);
void		ft_free_map(t_var *game);
void		ft_init_struct(t_var *game);
int			ft_is_valid_position(t_var *game, int x, int y, char ** visited);
void		ft_flood_fill(t_var *game, int x, int y, char ** visited);
void		ft_find_player_position(t_var *game, int *start_x, int *start_y);
void		ft_check_path(t_var *game);
void 		ft_cleanup(t_var *game);
#endif
