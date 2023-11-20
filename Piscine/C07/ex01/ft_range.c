/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 01:53:05 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/23 07:47:04 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	lentab;

	lentab = max - min;
	if (lentab < 1)
		return (NULL);
	else
	{
		tab = malloc(sizeof(int) * (lentab));
		if (!tab)
			return (NULL);
		i = 0;
		while (i < lentab)
		{
			tab[i] = (min + i);
			i++;
		}
	}
	return (tab);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	*result;
	int	i;

	min = 5;
	max = 10;
	result = ft_range(min, max);
	if (result)
	{
		i = 0;
		while (i < max - min)
		{
			printf("%d", result[i]);
			i++;
		}
		printf("\n");
		free(result);
	}
	else
	{
		printf("Invalid range.\n");
	}
	return (0);
}
*/
