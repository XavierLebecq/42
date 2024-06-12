/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:58:37 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 01:51:44 by xlebecq          ###   ########.fr       */
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
	int		exit_count;
	int		player_count;
	int		collectible_count;
	size_t	line_lenght;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
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
int			ft_is_surrounded_by_walls(t_var *game);
size_t		ft_strlen_whitout_nl(const char *s, t_var *game);
void		error_msg(char *msg, t_var *game);
void		perror_msg(char *msg);
void		ft_print_msg(t_var *game);
void		free_map(t_var *game);
void		init_game(t_var *game);

#endif