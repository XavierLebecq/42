/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:05:03 by cschmid           #+#    #+#             */
/*   Updated: 2024/04/17 15:52:19 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s1)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((s1[i] == ' ' || s1[i] == '\n' || s1[i] == '\t' || s1[i] == '\r'
			|| s1[i] == '\v' || s1[i] == '\f'))
		i++;
	if (s1[i] == '-')
		sign = -1;
	if (s1[i] == '+' || s1[i] == '-')
		i++;
	while (s1[i] >= '0' && s1[i] <= '9')
	{
		nb = nb * 10 + (s1[i] - '0');
		i++;
	}
	return (nb * sign);
}