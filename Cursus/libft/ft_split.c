/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:32:52 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/23 08:11:36 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_countsletter(const char *s, char c)
{
	size_t	letter;

	letter = 0;
	while (*s)
	{
		if (*s != c)
		{
			++letter;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (letter);
}

char	**ft_split(const char *s, char c)
{
	char	**letter;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	letter = malloc(sizeof(char *) * (ft_countsletter(s, c) + 1));
	if (!letter)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			letter[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	letter[i] = 0;
	return (letter);
}
