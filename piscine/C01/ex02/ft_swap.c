/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:31:53 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/09 10:22:50 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *chaussetterouge, int *chaussettebleu)
{
	int	troisiemetiroir;

	troisiemetiroir = *chaussetterouge;
	*chaussetterouge = *chaussettebleu;
	*chaussettebleu = troisiemetiroir;
}
/*
int	main(void)
{
	int	chaussetterouge;
	int	chaussettebleu;

	chaussetterouge = 1;
	chaussettebleu = 2;
	printf ("avant swap %d, %d\n", chaussetterouge, chaussettebleu);
	ft_swap(&chaussetterouge, &chaussettebleu);
	printf ("apres swap %d, %d\n", chaussetterouge, chaussettebleu);
	return (0);
}
*/
