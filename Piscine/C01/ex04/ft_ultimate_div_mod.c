/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:15:02 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/21 23:34:56 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a % *b;
	*a = *a / *b;
	*b = tmp;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 89;
	b = 40;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d", a, b);
}
*/
