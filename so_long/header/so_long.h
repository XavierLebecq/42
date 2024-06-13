/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:58:37 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 19:42:17 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_var
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	int		map_lines;
	char	**map;
	int		other;
	int		exit_count;
	int		player_count;
	int		collectible_count;
	int		line_lenght;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	char	current_char;
}			t_var;

int			handle_key(int key, t_var *game);
int			close_window(t_var *game);
void		ft_check_args(int argc, char **argv, t_var *game);
void		ft_check_map(t_var *game);
void		read_map(t_var *game);
void		ft_count_lines(char **argv, t_var *game);
void		ft_validate_map(t_var *game);
void		ft_display(t_var *game);
int			ft_is_rectangular(t_var *game);
void		ft_is_surrounded_by_walls(t_var *game);
int			ft_strlen_whitout_nl(const char *s);
void		error_msg(char *msg, t_var *game);
void		perror_msg(char *msg);
void		free_map(t_var *game);
void		init_game(t_var *game);
void 		print_map(t_var *game);
int 		is_valid_position(t_var *game, int x,int y, char **visited);
void    	flood_fill(t_var *game, int x, int y, char **visited);
void		find_player_position(t_var *game, int *start_x, int *start_y);
void		check_path(t_var *game);
#endif