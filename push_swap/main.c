/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:28:41 by xlebecq           #+#    #+#             */
/*   Updated: 2024/09/09 21:37:00 by neo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	long			nbr;
	long			i;
	struct s_list	 *next;
	struct s_list	 *prev;
}	t_list;

int	ft_atoi_check(char *str)
{
	int	i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] = '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if(ft_isdigit(str[i] == 1)
			ft_error_msg;
		result = result * 10 + str[i] - '0';
		i++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2141473648)
		ft_error_msg;
	return (result * sign);
}


void	ft_error_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

t_list	*ft_single_arg(char **argv)
{
	char **tab;
	
	tab = ft_split(argv[1], ' ');
	if(!tab)
		ft_error_msg();
	while(tab[i])
	{
		arg = ft_atoi_check(tab[i]);
		ft_lstaddback(&a, ft_lstnew(arg));
		i++;
	}
	free(tab);
}

t_list	*init_list(int argc, char **argv)
{
	int	i;
	t_list	*a;
	int	arg;

	i = 0;
	a = NULL;
	arg = 0;
	if (argc < 2)
		ft_error_msg();
	if (argc == 2)
		a = ft_single_arg(argv);
}

	
int main(int argc, char **argv)
{
	t_list *a;

	a = init_list(argc, argv);
}

