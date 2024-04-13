/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpointeurs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:00:16 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/12 16:43:33 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_test1(int xa)
{
	printf ("valeur de xa = %d\n", xa);
	printf ("adresse de xa = %p\n\n\n", &xa);
	return ;
}

void	ft_test2(int *xptr1)
{
	printf ("valeur de xptr1 = %p\n", xptr1);
	printf ("adresse de xptr1 = %p\n\n", &xptr1);
	printf ("valeur de *xptr1 = %d\n", *xptr1);
	printf ("adresse de *xptr1 = %p\n\n", &*xptr1);

	*xptr1 = 2; 

	return ;
}

void	ft_test3(int xptr1)
{
	printf ("valeur de xptr1 =%d\n", xptr1);
	printf ("adresse de xptr1 = %p\n\n", &xptr1);
	
	xptr1 = 10;
	return ;
}

int	main()
{
// MAIN 

	int	a;
	int	*ptr1;
	int	**ptr2;

	ptr1 = &a;	
	a = 5;
	
	printf ("\nMAIN\n\n");	
	printf ("valeur de a = %d\n", a);
	printf ("adresse de a = %p\n\n", &a);

	printf ("valeur de ptr1 = %p\n", ptr1);
	printf ("adresse de ptr1 = %p\n\n", &ptr1);
	printf ("valeur de *ptr1 = %d\n", *ptr1); 
	printf ("adresse de *ptr1 = %p\n\n\n", &*ptr1);


// TEST1

	printf("TEST1 on envoi a en parametre\n\n");
	ft_test1(a);

// TEST2

	printf("TEST2 on envoi ptr1 en parametre\n\n");
	ft_test2(ptr1);
	printf ("valeur de a apres ft_test2 = %d\n\n\n", a);

// TEST 3

	printf("TEST3 on envoi *ptr1 en parametre\n\n");
	ft_test3(*ptr1);
	printf ("valeur de a apres ft_test3 = %d\n\n\n", a);
	
	return (0);
}

