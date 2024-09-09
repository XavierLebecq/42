/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/25 14:13:01 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	game;

	ft_init_struct(&game);
	ft_check_args(argc, argv, &game);
	ft_count_lines(argv, &game);
	ft_read_map(&game);
	ft_validate_map(&game);
	ft_is_rectangular(&game);
	ft_is_surrounded_by_walls(&game);
	ft_find_player_position2(&game);
	ft_check_path(&game);
	ft_display(&game);
	return (0);
}
