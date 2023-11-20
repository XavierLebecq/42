/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:59:12 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/15 13:17:34 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;
	unsigned int	lendest;
	int				lensrc;

	i = 0;
	j = 0;
	while (dest[j])
	{
		j++;
	}
	lendest = j;
	lensrc = ft_strlen(src);
	if (size == 0 || size <= lendest)
		return (lensrc + size);
	while (src[i] != '\0' && i < size - lendest - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (lendest + lensrc);
}
/*
int	main(void)
{

	char src[] = "hellou";
	char dest[] = "world";
	printf("%i", ft_strlcat(dest, src, 2));
	printf("%s", dest);
}
*/