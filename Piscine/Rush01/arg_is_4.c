/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:12:28 by aherve            #+#    #+#             */
/*   Updated: 2023/08/13 15:25:30 by aherve           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	colup_is_4(int arg[4], int array[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 4)
		{
			j = 0;
			while (j < 4)
			{
				array[j][i] = 1 + j;
				j++;
			}
		}
		i++;
	}
}

void	coldown_is_4(int arg[4], int array[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 4)
		{
			j = 3;
			while (j != 0)
			{
				array[j][i] = 1 + j;
				j--;
			}
		}
		i++;
	}
}

void	rowleft_is_4(int arg[4], int array[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 4)
		{
			j = i;
			while (j < 4)
			{
				array[i][j] = 1 + j;
				j++;
			}
		}
		i++;
	}		
}

void	rowright_is_4(int arg[4], int array[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (arg[i] == 4)
		{
			j = 3;
			while (j != 0)
			{
				array[i][j] = j + 1;
				j--;
			}
		}
		i++;
	}
}

void	arg_is_4(int arg[4][4], int array[4][4])
{
	int	*colup;
	int	*coldown;
	int	*rowleft;
	int	*rowright;

	colup = &arg[0][0];
	coldown = &arg[1][0];
	rowleft = &arg[2][0];
	rowright = &arg[3][0];
	colup_is_4(colup, array);
	coldown_is_4(coldown, array);
	rowleft_is_4(rowleft, array);
	colup_is_4(rowright, array);
}
