/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:44:53 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/21 17:01:02 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	while (power > 1)
	{
		i = i * nb;
		power--;
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (i);
}
/*
int	main(void)
{
	printf ("%d", ft_iterative_power(2, 4));
}
*/
