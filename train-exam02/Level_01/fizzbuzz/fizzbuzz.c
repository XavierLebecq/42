/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:54:16 by xlebecq           #+#    #+#             */
/*   Updated: 2024/01/25 02:38:39 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	conv;

	conv = (nbr + '0');
	if (nbr <= 9)
	{
		write(1, &conv, 1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	main(void)
{
	int	nbr;

	nbr = 1;
	while (nbr <= 100)
	{
		if (nbr % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (nbr % 3 == 0)
			write (1, "fizz", 4);
		else if (nbr % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_putnbr(nbr);
		write (1, "\n", 1);
		nbr++;
	}
}
