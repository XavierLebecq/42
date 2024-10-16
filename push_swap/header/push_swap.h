/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:47:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/16 21:50:10 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_stack_node
{
	int				nbr;
	struct s_stack_node	 *next;
	struct s_stack_node	 *prev;
}	stack_node;

typedef struct	s_stacks
{
	stack_node	*a;
	stack_node	*b;
}	stacks;

void	ft_split_single_arg(stack_node **a, char **argv);
void	ft_error_and_exit(void);
int		ft_atoi_check(const char *input_args, char **args_split);
void	ft_stack_add_back(stack_node **head, stack_node *new_node);
stack_node	*ft_stack_last_node(stack_node *node);
stack_node	*ft_stack_new_node(int content);
void    ft_free_split_result(char **args_split);
int		ft_stack_size(stack_node *node);
int		ft_has_duplicates(stack_node *a);
void	ft_parse_multi_arg(stack_node **a, int argc, char **argv, char **args_split);
void	ft_free_stack(stack_node **node);
int		ft_is_unsorted(stack_node *a);
void	ft_sa(stack_node **a);
void	ft_rr(stack_node **a, stack_node **b);
void	ft_rrr(stack_node **a, stack_node **b);
void	ft_rrr2(stack_node **b);
void	ft_sort_stack(stack_node **a, stack_node **b);
void	ft_rra(stack_node **a);
void	ft_rb(stack_node **b);
void	ft_rrb(stack_node **b);
void	ft_sort_stack_of_three(stack_node **a);
int		ft_find_min_value(stack_node *a);
int		ft_find_max_value(stack_node *a);
void    ft_ra(stack_node **a);
void	ft_pb(stack_node **a, stack_node **b);
void    ft_pa(stack_node **a, stack_node **b);
void	ft_push_elements_to_b(stack_node **a, stack_node **b);
void	ft_push_elements_to_a(stack_node **a, stack_node **b);
void	ft_sort_stack_over_three(stack_node **a, stack_node **b);
int		ft_calculate_push_cost_b(stack_node *a, stack_node *b);
int		ft_calculate_push_cost_a(stack_node *a, stack_node *b);
int		ft_cost_rrarrb_b(stack_node *a, stack_node *b, int nbr);
int		ft_find_insert_position_b(stack_node *b, int insert_value);
int		ft_find_insert_position_a(stack_node *a, int insert_value);
int		ft_find_index_in_stack(stack_node *a, int target_value);
int		ft_cost_rrarb_b(stack_node *a, stack_node *b, int nbr);
int		ft_cost_rarb_b(stack_node *a, stack_node *b, int nbr);
int		ft_cost_rarrb_b(stack_node *a, stack_node *b, int nbr);
int		ft_execute_rarb_b(stack_node **a, stack_node **b, int nbr);
int		ft_execute_rrarrb_b(stack_node **a, stack_node **b, int nbr);
int		ft_execute_rrarb_b(stack_node **a, stack_node **b, int nbr);
int		ft_execute_rarrb_b(stack_node **a, stack_node **b, int nbr);
int		ft_cost_rarb_a(stack_node *a, stack_node *b, int nbr);
int		ft_cost_rrarrb_a(stack_node *a, stack_node *b, int nbr);
int		ft_cost_rarrb_a(stack_node *a, stack_node *b, int nbr);
int		ft_cost_rrarb_a(stack_node *a, stack_node *b, int nbr);
int		ft_execute_rarb_a(stack_node **a, stack_node **b, int nbr);
int		ft_execute_rrarrb_a(stack_node **a, stack_node **b, int nbr);
int		ft_execute_rrarb_a(stack_node **a, stack_node **b, int nbr);
int		ft_execute_rarrb_a(stack_node **a, stack_node **b, int nbr);
void 	ft_move_min_to_top(stack_node **a);

#endif
