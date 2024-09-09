/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:32:45 by xlebecq           #+#    #+#             */
/*   Updated: 2023/08/20 18:26:43 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	buffer_len(char *str)
{
	int		fd;
	int		taille;
	char	c;

	taille = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1))
		taille++;
	close(fd);
	return (taille);
}

char	*read_dict(char *st)
{
	int		fd;
	int		sz;
	char	*buf;
	int		taille;

	taille = buffer_len(st);
	if (taille == -1)
	{
		write(1, "Error\n", 6);
		return ("\0");
	}
	buf = malloc(sizeof(char) * taille);
	if (buf == NULL)
		return (0);
	fd = open(st, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error", 5);
		return (NULL);
	}
	sz = read(fd, buf, taille);
	close(fd);
	return (buf);
}

int	ft_number(char *str)
{
	int	i;
	int	j;
	int	sign_neg;
	int	sign_pos;

	i = 0;
	j = 0;
	sign_neg = 0;
	sign_pos = 0;
	while (str[i] == ' ' || (str[i] >= '\t' & str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign_neg++;
		if (str[i] == '+')
			sign_pos++;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		str[j++] = str[i++];
	str[j] = '\0';
	if (sign_neg != 0 || sign_pos > 1)
		return (-1);
	return (0);
}

int	ft_strstr(char *str, char *to_find, char *tab)
{
	int	i;
	int	a;
	int	k;

	i = 0;
	if (*to_find == '\0')
		return (1);
	while (str[i] != '\0')
	{
		k = 0;
		a = 0;
		while (str[i + a] == to_find[a])
		{
			if (to_find[1 + a] == '\0')
			{
				while (str[i] != '\n')
					tab[k++] = str[i++];
				tab[k] = '\0';
				return (0);
			}
			a++;
		}
		i++;
	}
	return (0);
}

void	ft_pars(char *buffer, char *to_find)
{
	int		i;
	char	tab[1024];

	i = 0;
	ft_strstr(buffer, to_find, tab);
	while (tab[i])
	{
		while (tab[i] >= '0' && tab[i] <= '9')
			i++;
		while (tab[i] == 58)
			i++;
		while (tab[i] == 32)
			i++;
		while (tab[i] != '\0')
		{
			write(1, &tab[i], 1);
			i++;
		}
	}
}
