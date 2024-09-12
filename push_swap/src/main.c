/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:04:20 by xlebecq           #+#    #+#             */
/*   Updated: 2024/09/12 20:46:36 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*ft_single_arg(char **argv)
{
	t_swap *a;
	char **tab;
	int	i;
	int arg;

	i = 0;
	arg = 0;
	a = NULL;
	tab = ft_split(argv[1], ' ');
	if(!tab)
		ft_error_msg();
	while(tab[i])
	{
		arg = ft_atoi_check(tab[i]);
		ft_lstaddback(&a, ft_stack_new(arg));
		i++;
	}
	ft_free_tab(tab);
	free(tab);
	return (a);
}

t_swap	*ft_multi_arg(int argc, char **argv)
{
	t_swap *a;
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	a = NULL;
	while(++i < argc)
	{
		nbr = ft_atoi_check(argv[i]);
		ft_lstaddback(&a, ft_stack_new(nbr));
	}
	return (a);
}


t_swap	*init_list(int argc, char **argv)
{
	t_swap	*a;
	if (argc < 2)
		ft_error_msg();
	else if (argc == 2)
		a = ft_single_arg(argv);
	else
		a = ft_multi_arg(argc, argv);
	if (!a || ft_check_double(a))
	{
		ft_error_msg();
		ft_free_list(&a);
	}
	return (a);
}	
	
int main(int argc, char **argv)
{
	t_swap *a;
	a = init_list(argc, argv);
	if (ft_check_order(a) == 1)
		ft_sort(&a);
	ft_free_list(&a);
}
