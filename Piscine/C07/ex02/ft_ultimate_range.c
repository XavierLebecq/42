/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:54:54 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/23 08:00:48 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*tab;

	tab = NULL;
	if (min >= max)
		return (NULL);
	len = max - min;
	tab = malloc(sizeof(int) * len);
	if (tab == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len)
		{
			tab[i] = min;
			min++;
			i++;
		}
		return (tab);
	}
}

int	ft_ultimate_range(int *range[], int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		*range = ft_range(min, max);
	}
	return (max - min);
}

int	main(void)
{
    int *range;
    int min;
    int max;
    int len;
    int i;

	min = 0;
	max = 10;
	i = 0;
	len = ft_ultimate_range(&range, min, max);
	if (len <= 0)
		return (0);
	while (i < len)
	{
		printf("%d\n", range[i]);
		i++;
	}
	return (0);
}

