/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:12:28 by aherve            #+#    #+#             */
/*   Updated: 2023/08/13 18:31:01 by aherve           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_in_tab(int nb, int array[4][4], int line, int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (array[line][i] == nb)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (array[i][col] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	not_max_score(int nb, int array[4][4], int line, int col)
{
	int	i;
	int	score;

	i = 0;
	score = 0;
	while (i < 4)
	{
		score += array[line][i];
		i++;
	}
	score += nb;
	if (score > 10)
		return (0);
	i = 0;
	score = 0;
	while (i < 4)
	{
		score += array[i][col];
		i++;
	}
	score += nb;
	if (score > 10)
		return (0);
	return (1);
}

int	calcul(int arg[4][4], int array[4][4], int position)
{
	int	i;
	int	j;
	int	k;

	if (position == 16)
		return (1);
	i = position / 4;
	j = position % 4;
	if (array[i][j] != 0)
		return (calcul(arg, array, position + 1));
	k = 1;
	while (k <= 4)
	{
		if (not_in_tab(k, array, i, j) == 1
			&& not_max_score(k, array, i, j) == 1)
		{
			array[i][j] = k;
			if (calcul(arg, array, position + 1) == 1)
				return (1);
		}
		k++;
	}
	array[i][j] = 0;
	return (0);
}
