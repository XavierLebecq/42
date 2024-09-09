/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_21.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:58:05 by aherve            #+#    #+#             */
/*   Updated: 2023/08/13 15:21:44 by aherve           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cols_are_21(int colup[4], int coldown[4], int array[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (colup[i] == 2 && coldown[i] == 1)
			array[0][i] = 3;
		if (colup[i] == 1 && coldown[i] == 2)
			array[3][i] = 3;
		i++;
	}
}

void	rows_are_21(int rowleft[4], int rowright[4], int array[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (rowleft[i] == 2 && rowright[i] == 1)
			array[i][0] = 3;
		if (rowleft[i] == 1 && rowright[i] == 2)
			array[i][3] = 3;
		i++;
	}
}

void	arg_is_21(int arg[4][4], int array[4][4])
{
	int	*colup;
	int	*coldown;
	int	*rowleft;
	int	*rowright;

	colup = &arg[0][0];
	coldown = &arg[1][0];
	rowleft = &arg[2][0];
	rowright = &arg[3][0];
	cols_are_21(colup, coldown, array);
	rows_are_21(rowleft, rowright, array);
}
