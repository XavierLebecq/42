/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:12:28 by aherve            #+#    #+#             */
/*   Updated: 2023/08/13 17:58:26 by aherve           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	argv_without_spaces(char *argv, char *instruction);
void	char_to_int(char *instruction, int arg[4][4]);
void	init_array_to_zero(int array[4][4]);
void	display_array(int array[4][4]);
void	arg_is_4(int arg[4][4], int array[4][4]);
void	arg_is_1(int arg[4][4], int array[4][4]);
void	arg_is_21(int arg[4][4], int array[4][4]);
int		calcul(int arg[4][4], int array[4][4], int position);

int	ft_strlen(char *instruction)
{
	int	i;

	i = 0;
	while (instruction[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	instruction[16];
	int		array[4][4];
	int		arg[4][4];

	(void)argc;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	argv_without_spaces(argv[1], instruction);
	if (ft_strlen(instruction) != 16)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	char_to_int(instruction, arg);
	init_array_to_zero(array);
	arg_is_4(arg, array);
	arg_is_1(arg, array);
	arg_is_21(arg, array);
	calcul(arg, array, 0);
	display_array(array);
	return (0);
}
