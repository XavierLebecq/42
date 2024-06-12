/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 01:47:43 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	game;

	init_game(&game);
	ft_check_args(argc, argv, &game);
	ft_count_lines(argv, &game);
	read_map(&game);
	ft_check_map(&game);
	ft_validate_map(&game);
	free_map(&game);
	ft_display(&game);
	return (0);
}
