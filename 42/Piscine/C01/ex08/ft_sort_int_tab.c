/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:43:53 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/20 15:45:13 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}
/*
int	main(void)
{
int		size;

int		tab[6] = {7, 6, 5, 3, 1, 0};
size = 6;
ft_sort_int_tab(tab, size);
printf ("%d, %d, %d, %d, %d, %d", tab[0], tab[1], tab[2], tab[3], tab[4],
	tab[5]);
}
*/