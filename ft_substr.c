/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:49:52 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/16 21:13:11 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char *str;

	if (!s)
		return (NULL);

	i = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > (ft_strlen(s)))
		len = ft_strlen(s) - start;
	j = 0;
	str = (char *)malloc(len + 1);
	if (!str || !s)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}