/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:32:21 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/20 18:02:46 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_number(argv[1]) == -1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		ft_number(argv[1]);
        ft_pars(read_dict("numbers.dict"), argv[1]);
		free(read_dict("numbers.dict"));
	}
	if (argc == 3)
	{
		if (ft_number(argv[2]) == -1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
        ft_number(argv[2]);
		ft_pars(read_dict(argv[1]), argv[2]);
		free(read_dict(argv[1]));
	}
	return (0);
}
