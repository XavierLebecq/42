/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:47:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/11 13:55:16 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_swap
{
	long			nbr;
	long			index;
	struct s_swap	 *next;
	struct s_swap	 *prev;
}	t_swap;

t_swap	*init_list(int argc, char **argv);
t_swap	*ft_single_arg(char **argv);
void	ft_error_msg(void);
void	ft_lstaddback(t_swap **stack, t_swap *stack_new);
t_swap	*ft_lstlast2(t_swap *lst);
int		ft_atoi_check(char *str);
t_swap	*ft_stack_new(int content);
void    ft_free_tab(char **tab);
t_swap	*ft_stack_new(int content);
int		ft_check_double(t_swap *a);
t_swap	*ft_multi_arg(int argc, char **argv);
void	ft_free_list(t_swap **lst);
int		ft_check_order(t_swap *a);
void	ft_sa(t_swap **a);
void	ft_rr(t_swap **a, t_swap **b);
void	ft_rrr(t_swap **a, t_swap **b);
void	ft_sort(t_swap **a, t_swap **b);
int		ft_lstsize2(t_swap *lst);
void	ft_rra(t_swap **a);
void	ft_rb(t_swap **b);
void	ft_rrb(t_swap **b);
void	ft_int_three(t_swap **a);
int		ft_int_min(t_swap *a);
int		ft_int_max(t_swap *a);
void    ft_ra(t_swap **a);
void	ft_pb(t_swap **a, t_swap **b);
void	ft_push_b(t_swap **a, t_swap **b);
void	ft_push_a(t_swap **a, t_swap **b);
void	ft_sort_more_3(t_swap **a, t_swap **b);
int		ft_cost_a(t_swap *a, t_swap *b);
int		ft_cost_b(t_swap *a, t_swap *b);
int		ft_cost_rrarrb_b(t_swap *a, t_swap *b, int nbr);
int		ft_index_b(t_swap *b, int nbr);
int		ft_index_a(t_swap *a, int nbr);
int		ft_position(t_swap *a, int nbr);
int		ft_cost_rrarb_b(t_swap *a, t_swap *b, int nbr);
int		ft_cost_rarb_b(t_swap *a, t_swap *b, int nbr);
int		ft_cost_rarrb_b(t_swap *a, t_swap *b, int nbr);
int		ft_apply_rarb_b(t_swap **a, t_swap **b, int nbr);
int		ft_apply_rrarrb_b(t_swap **a, t_swap **b, int nbr);
int		ft_apply_rrarb_b(t_swap **a, t_swap **b, int nbr);
int		ft_apply_rarrb_b(t_swap **a, t_swap **b, int nbr);
int		ft_cost_rarb_a(t_swap *a, t_swap *b, int nbr);
int		ft_cost_rrarrb_a(t_swap *a, t_swap *b, int nbr);
int		ft_cost_rarrb_a(t_swap *a, t_swap *b, int nbr);
int		ft_cost_rrarb_a(t_swap *a, t_swap *b, int nbr);

#endif
