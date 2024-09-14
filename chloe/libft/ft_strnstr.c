/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:57:54 by cschmid           #+#    #+#             */
/*   Updated: 2023/12/29 14:26:13 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*str2 == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == str2[j] && i + j < len)
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
