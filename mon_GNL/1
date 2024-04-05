/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:01:33 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/02 14:17:50 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_chain	*ft(t_chain *last, int number)
{
	t_chain	*new;

	new = (t_chain *)malloc(12);
	last->next = new;
	new->num = number;
	new->next = NULL;
	return (new);
}

#include <stdio.h>

int	main()
{
	t_chain	 *first;

	first = (t_chain *)malloc(sizeof(t_chain));
	
	first->num = 0;
	first->next = NULL;


	int	i = 1;
	t_chain	*temp = first;

	while (i < 30)
	{
		temp = ft(temp, i);
		i++;
	}
	temp = first;
	while (temp != NULL)
	{
		printf("=%d\n", temp->num);
		temp = temp->next;
	}
	return 0;
}

