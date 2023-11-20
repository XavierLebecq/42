/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:52:22 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/24 17:22:54 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	c;
	int	result;

	i = 0;
	c = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
	{
		i++;
	}
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
		{
			c = c * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * c);
}

int	main(void)
{

	char str[] = "    +42";
	printf("%d", ft_atoi(str));
	return (0);
}

