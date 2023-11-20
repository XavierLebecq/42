/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:01:51 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/16 21:39:42 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_width(int n)
{
	size_t	width;

	width = (n <= 0);
	while (n)
	{
		n /= 10;
		width++;
	}
	return (width);
}

char			*ft_itoa(int n)
{
	char			*num;
	int				rem;
	size_t			i;
	const char		neg = (n < 0);
	const size_t	width = get_width(n);

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (!(num = ft_calloc(width + 1, sizeof(char))))
		return (NULL);
	n = (neg) ? -n : n;
	i = 0;
	while (i < width)
	{
		rem = n % 10;
		n = n / 10;
		num[i] = "0123456789"[rem];
		i++;
	}
	if (neg)
		num[i - 1] = '-';
	return (ft_strrev(num));
}
