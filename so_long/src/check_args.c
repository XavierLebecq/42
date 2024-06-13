/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:20:19 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/12 16:26:52 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv, t_var *game)
{
	if (argc != 2)
		error_msg("Error: invalid number of arguments.\n", NULL);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		error_msg("Error: invalid map file extension. Expected a '.ber' file.\n",
			NULL);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		perror_msg("Error opening file");
}
