/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:43:33 by xlebecq           #+#    #+#             */
/*   Updated: 2023/11/16 16:42:42 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_char;
	const char	*src_char = (const char *)src;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_char = (char *)dst;
	if (src_char < dst_char)
	{
		while (len--)
			*(dst_char + len) = *(src_char + len);
	}
	else
	{
		while (len--)
			*dst_char++ = *src_char++;
	}
	return (dst);
}
