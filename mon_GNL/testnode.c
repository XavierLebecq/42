/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:09:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/04/14 18:17:56 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct blabla
{
	char			*content;
	struct blabla	*next;
}					pokito;

int	main()
{
	char	*str;
	pokito	*new_node;

	str = "bonjour";
	new_node = malloc (sizeof(pokito));
	new_node->content = str;
	new_node->next = NULL;
	printf ("%s", new_node->content);
	return (0);
}
