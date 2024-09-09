/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:07:04 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/23 07:51:57 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	strs_size(char **strs, char *sep, int size)
{
	int	i;
	int	len_all;

	if (size == 0)
		return (1);
	i = 0;
	len_all = 0;
	while (i < size)
	{
		len_all = len_all + ft_strlen(strs[i]);
		i++;
	}
	len_all = len_all + ft_strlen(sep) * (size - 1);
	return (len_all);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_tab;
	int		i;

	final_tab = malloc((strs_size(strs, sep, size) + 1) * sizeof(char));
	if (final_tab == NULL)
		return (NULL);
	final_tab[0] = '\0';
	if (size == 0)
		return (final_tab);
	i = 0;
	while (i < size)
	{
		ft_strcat(final_tab, strs[i]);
		if (i != size - 1)
			ft_strcat(final_tab, sep);
		i++;
	}
	return (final_tab);
}
/*
int	main(int argc, char **argv)
{
	char *sep = "-";
	char *result = ft_strjoin(argc - 1, &argv[1], sep);

	if (result != NULL)
	{
		printf("Tab : %s\n", result);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
*/
