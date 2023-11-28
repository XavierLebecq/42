/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:25:17 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/28 16:07:56 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sign(char *str, long *nb)
{
	if ((*nb) == 0)
		str[0] = '0';
	if ((*nb) < 0)
	{
		str[0] = '-';
		*nb = -*nb;
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		nbr;
	short int	j;
	char		str[13];
	long		nb;

	nb = n;
	j = 0;
	nbr = 1000000000;
	ft_bzero(str, 13);
	i = ft_sign(str, &nb);
	while (nbr != 0)
	{
		if (nb / nbr != 0 || j != 0)
		{
			str[i++] = (nb / nbr) + 48;
			j++;
		}
		nb %= nbr;
		nbr /= 10;
	}
	return (ft_strdup(str));
}
