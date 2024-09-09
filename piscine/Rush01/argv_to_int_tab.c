/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:12:28 by aherve            #+#    #+#             */
/*   Updated: 2023/08/13 17:26:07 by aherve           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	argv_without_spaces(char *argv, char *instruction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			instruction[j] = argv[i];
			j++;
		}
		i++;
	}
	instruction[j] = '\0';
}

void	char_to_int(char *instruction, int arg[4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			arg[j][k] = instruction[i] - '0';
			i++;
			k++;
		}
		j++;
	}
}
