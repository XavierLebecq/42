/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:47:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/15 03:08:32 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	long			nbr;
	long			index;
	struct s_stack	 *next;
	struct s_stack	 *prev;
}	stack;

/*typedef struct	s_stacks
{
	stack	*a;
	stack	*b;
}	stacks;
*/

stack	*init_list(int argc, char **argv);
stack	*ft_single_arg(char **argv);
void	ft_error_msg(void);
void	ft_lstaddback(stack **head, stack *new_node);
stack	*ft_lstlast2(stack *lst);
int		ft_atoi_check(char *str);
stack	*ft_stack_new(int content);
void    ft_free_tab(char **tab);
int		ft_check_double(stack *a);
stack	*ft_multi_arg(int argc, char **argv);
void	ft_free_list(stack **lst);
int		ft_check_order(stack *a);
void	ft_sa(stack **a);
void	ft_rr(stack **a, stack **b);
void	ft_rrr(stack **a, stack **b);
void	ft_rrr2(stack **b);
void	ft_sort(stack **a, stack **b);
int		ft_lstsize2(stack *lst);
void	ft_rra(stack **a);
void	ft_rb(stack **b);
void	ft_rrb(stack **b);
void	ft_int_three(stack **a);
int		ft_int_min(stack *a);
int		ft_int_max(stack *a);
void    ft_ra(stack **a);
void	ft_pb(stack **a, stack **b);
void    ft_pa(stack **a, stack **b);
void	ft_push_b(stack **a, stack **b);
void	ft_push_a(stack **a, stack **b);
void	ft_sort_more_3(stack **a, stack **b);
int		ft_cost_a(stack *a, stack *b);
int		ft_cost_b(stack *a, stack *b);
int		ft_cost_rrarrb_b(stack *a, stack *b, int nbr);
int		ft_index_b(stack *b, int nbr);
int		ft_index_a(stack *a, int nbr);
int		ft_position(stack *a, int nbr);
int		ft_cost_rrarb_b(stack *a, stack *b, int nbr);
int		ft_cost_rarb_b(stack *a, stack *b, int nbr);
int		ft_cost_rarrb_b(stack *a, stack *b, int nbr);
int		ft_apply_rarb_b(stack **a, stack **b, int nbr);
int		ft_apply_rrarrb_b(stack **a, stack **b, int nbr);
int		ft_apply_rrarb_b(stack **a, stack **b, int nbr);
int		ft_apply_rarrb_b(stack **a, stack **b, int nbr);
int		ft_cost_rarb_a(stack *a, stack *b, int nbr);
int		ft_cost_rrarrb_a(stack *a, stack *b, int nbr);
int		ft_cost_rarrb_a(stack *a, stack *b, int nbr);
int		ft_cost_rrarb_a(stack *a, stack *b, int nbr);
int		ft_apply_rarb_a(stack **a, stack **b, int nbr);
int		ft_apply_rrarrb_a(stack **a, stack **b, int nbr);
int		ft_apply_rrarb_a(stack **a, stack **b, int nbr);
int		ft_apply_rarrb_a(stack **a, stack **b, int nbr);

#endif
