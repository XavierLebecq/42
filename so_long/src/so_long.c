/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/29 17:55:46 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		write (1, "Error, invalid number of arguments\n", 35);
		exit (0);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1])-4], ".ber", 4) != 0)
		return (write (1, "Error, invalid map file extension\n", 34));
		
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit (0);
	}
	char *string = get_next_line(fd);
	ft_printf("%s\n", string);
	free(string);
	
/*
	char ** = NULL
	char ** = {gnl0, NULL}
	char ** = {gnl0, gnl1, NULL}
*/
	
    void *mlx;
    void *win;
	void *img;
	int img_width;
	int img_height;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 600, "So Long");

	img = mlx_xpm_file_to_image(mlx, "/home/xlebecq/Documents/42/so_long/herbe.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_hook(win, 2, 1L << 0, handle_key, NULL);
	mlx_hook(win, 17, 1L << 17, close_window, NULL);

    mlx_loop(mlx);


    return 0;
}
