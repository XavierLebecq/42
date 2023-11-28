/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:30:56 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/28 14:30:06 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!s || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	return (ft_substr(s, start, end - start));
}
