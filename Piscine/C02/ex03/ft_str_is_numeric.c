/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:15:18 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/17 18:42:24 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] <= 47 || str[i] >= 58))                                                                                                                                                                                                                                                         
		{
			return (0);
		}
		++i;
	}
	return (1);
}
/*
int	main(void)
{
	int		is_numeric;
	char	a[];

	a[] = "111";
	is_numeric = ft_str_is_numeric(a);
	printf ("%d\n", is_numeric);
}
*/