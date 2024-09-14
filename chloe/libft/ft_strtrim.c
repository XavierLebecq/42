/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:04:14 by cschmid           #+#    #+#             */
/*   Updated: 2023/12/28 09:57:13 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if ((s1 != 0) && (set != 0))
	{
		i = 0;
		while ((s1[i]) && (ft_strchr(set, s1[i])))
			i++;
		j = ft_strlen(s1);
		while ((s1[j - 1]) && (ft_strchr(set, s1[j - 1]) && j > i))
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!str)
			return (NULL);
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	else
		return (0);
	return (str);
}
