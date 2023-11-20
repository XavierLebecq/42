/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:12:28 by aherve            #+#    #+#             */
/*   Updated: 2023/08/13 15:18:29 by aherve           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	colup_is_1(int arg[4], int array[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 1)
			array[i][0] = 4;
		i++;
	}
}

void	coldown_is_1(int arg[4], int array[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 1)
			array[3][i] = 4;
		i++;
	}
}

void	rowleft_is_1(int arg[4], int array[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 1)
			array[0][i] = 4;
		i++;
	}
}

void	rowright_is_1(int arg[4], int array[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 1)
			array[3][i] = 4;
		i++;
	}
}

void	arg_is_1(int arg[4][4], int array[4][4])
{
	int	*colup;
	int	*coldown;
	int	*rowleft;
	int	*rowright;

	colup = &arg[0][0];
	coldown = &arg[1][0];
	rowleft = &arg[2][0];
	rowright = &arg[3][0];
	colup_is_1(colup, array);
	coldown_is_1(coldown, array);
	rowleft_is_1(rowleft, array);
	rowright_is_1(rowright, array);
}
