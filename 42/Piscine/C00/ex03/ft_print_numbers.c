/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:30:35 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/09 10:09:51 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	nombre;

	nombre = '0';
	while (nombre <= '9')
	{
		write (1, &nombre, 1);
		nombre++;
	}
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/
