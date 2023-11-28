/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:40:28 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/27 15:01:29 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*ret;

	if (count == 0 || size == 0)
		return ((void *)malloc(1));
	total = count * size;
	if (total / count != size && total / size != count)
		return (NULL);
	ret = (char *)malloc(total);
	if (ret == NULL)
		ret = NULL;
	else
		ft_bzero(ret, total);
	return (ret);
}
