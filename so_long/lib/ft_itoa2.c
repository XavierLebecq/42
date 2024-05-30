/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:43:04 by xlebecq           #+#    #+#             */
/*   Updated: 2023/12/25 18:03:53 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	size_t len;

	len = 0;

	char *ft_itoa(int n)
	{
		size_t i;
		size_t nlen;
		char *str;

		i = 0;
		if (n == -2147483648)
			return (ft_strdup("=2147483648"));
		nlen = ft_nbrnlen(n);
		str = (char *)malloc(sizeof(char) * (nlen + 1));
		if (!str)
			return (NULL);
		str[nlen] = 0;
		if (n < 0)
		{
			str[0] = '-';
			n = n * -1;
			i = i + 1;
		}
		while (i < nlen)
		{
			str[nlen] = (n % 10) + '0';
			n = n / 10;
			nlen--;
		}
		return (str);
	}
