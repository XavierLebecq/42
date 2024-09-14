/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/12/18 12:28:22 by cschmid           #+#    #+#             */
/*   Updated: 2024/04/17 15:38:42 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **f)
{
	size_t	i;

	i = 0;
	while (f[i])
	{
		free(f[i]);
		i++;
	}
	free(f);
	return (0);
}

static int	ft_wordcount(const char *str, char c)
{
	int	wordcount;
	int	sep;

	wordcount = 0;
	sep = 0;
	while (*str)
	{
		if (*str != c && sep == 0)
		{
			sep = 1;
			wordcount++;
		}
		else if (*str == c)
			sep = 0;
		str++;
	}
	return (wordcount);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	result = malloc((ft_wordcount(s, c) + 2) * sizeof(char *));
	if (!result)
		return (0);
	i = 1;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while ((*s) && (*s != c) && (++j))
				s++;
			result[0] = 0;
			result[i] = ft_substr(s - j, 0, j);
			if (!result[i++])
				return (ft_free(result));
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
