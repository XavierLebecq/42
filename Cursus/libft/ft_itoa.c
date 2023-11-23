/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:01:51 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/23 08:10:46 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_length(int n)
{
	size_t	length;

	length = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*str;

	length = get_number_length(n);
	if (n < 0)
	{
		length++;
	}
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	str[length] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	else if (n < 0)
	{
		str[0] = '-';
	}
	while (n != 0)
	{
		if (n < 0)
		{
			str[--length] = '0' - (n % 10);
		}
		else
		{
			str[--length] = '0' + (n % 10);
		}
		n /= 10;
	}
	return (str);
}
