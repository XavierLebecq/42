/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:47:29 by xlebecq           #+#    #+#             */
/*   Updated: 2024/01/25 18:36:19 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 2)
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				j = argv[1][i] - 64;
				while (j > 0)
				{
					write (1, &argv[1][i], 1);
					j--;
				}
				i++;
			}
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
                                j = argv[1][i] - 96;
                                while (j > 0)
                                {
                                        write (1, &argv[1][i], 1);
                                        j--;
                                }       
                                i++;
                        }
	
		}
		write (1, "\n", 1);
}	
