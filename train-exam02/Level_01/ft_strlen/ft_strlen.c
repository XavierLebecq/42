/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:39:56 by xlebecq           #+#    #+#             */
/*   Updated: 2024/01/25 03:46:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])

		i++;
	return (i);
}

int	main(void)
{
	char	*str;

	str = "bonjour";
	printf ("%i", ft_strlen(str));
	return (0);
}
