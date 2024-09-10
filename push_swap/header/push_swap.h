/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:47:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/09/09 23:00:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_swap
{
	long			nbr;
	long			i;
	struct s_swap	 *next;
	struct s_swap	 *prev;
}	t_swap;

#endif
