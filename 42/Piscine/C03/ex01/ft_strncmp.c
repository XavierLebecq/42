/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:31:20 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/15 16:13:37 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && i < n - 1 && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}


int	main(void)
{
	printf("%d", ft_strncmp("bonjour", "conjour", (3)));
	return (0);
}

