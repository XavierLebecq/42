/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:47:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/10/17 17:36:09 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_t_stack_node
{
	int						nbr;
	struct s_t_stack_node	*next;
	struct s_t_stack_node	*prev;
}	t_stack_node;

typedef struct s_stacks
{
	t_stack_node	*a;
	t_stack_node	*b;
}	t_stacks;

void			ft_split_single_arg(t_stack_node **a, char **argv);
void			ft_atoi_and_push(const char *input_args, char **args_split,
					t_stack_node **a);
void			ft_stack_add_back(t_stack_node **head, t_stack_node *new_node);
t_stack_node	*ft_stack_last_node(t_stack_node *node);
t_stack_node	*ft_stack_new_node(int content);
int				ft_stack_size(t_stack_node *node);
int				ft_has_duplicates(t_stack_node *a);
void			ft_multi_arg(t_stack_node **a, int argc, char **argv);
int				ft_is_unsorted(t_stack_node *a);
void			ft_sa(t_stack_node **a);
void			ft_rr(t_stack_node **a, t_stack_node **b);
void			ft_rrr(t_stack_node **a, t_stack_node **b);
void			ft_rrr2(t_stack_node **b);
void			ft_sort_stack(t_stack_node **a, t_stack_node **b);
void			ft_rra(t_stack_node **a);
void			ft_rb(t_stack_node **b);
void			ft_rrb(t_stack_node **b);
void			ft_sort_stack_of_three(t_stack_node **a);
int				ft_find_min_value(t_stack_node *a);
int				ft_find_max_value(t_stack_node *a);
void			ft_ra(t_stack_node **a);
void			ft_pb(t_stack_node **a, t_stack_node **b);
void			ft_pa(t_stack_node **a, t_stack_node **b);
void			ft_push_elements_to_a(t_stack_node **a, t_stack_node **b);
void			ft_sort_stack_over_three(t_stack_node **a, t_stack_node **b);
int				ft_calculate_push_cost_b(t_stack_node *a, t_stack_node *b);
int				ft_calculate_push_cost_a(t_stack_node *a, t_stack_node *b);
int				ft_cost_rrarrb_b(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_find_insert_position_b(t_stack_node *b, int insert_value);
int				ft_find_insert_position_a(t_stack_node *a, int insert_value);
int				ft_find_index_in_stack(t_stack_node *a, int target_value);
int				ft_cost_rrarb_b(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_cost_rarb_b(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_cost_rarrb_b(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_execute_rarb_b(t_stack_node **a, t_stack_node **b, int nbr);
int				ft_execute_rrarrb_b(t_stack_node **a, t_stack_node **b,
					int nbr);
int				ft_execute_rrarb_b(t_stack_node **a, t_stack_node **b, int nbr);
int				ft_execute_rarrb_b(t_stack_node **a, t_stack_node **b, int nbr);
int				ft_cost_rarb_a(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_cost_rrarrb_a(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_cost_rarrb_a(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_cost_rrarb_a(t_stack_node *a, t_stack_node *b, int nbr);
int				ft_execute_rarb_a(t_stack_node **a, t_stack_node **b, int nbr);
int				ft_execute_rrarrb_a(t_stack_node **a, t_stack_node **b,
					int nbr);
int				ft_execute_rrarb_a(t_stack_node **a, t_stack_node **b, int nbr);
int				ft_execute_rarrb_a(t_stack_node **a, t_stack_node **b, int nbr);
void			ft_move_min_to_top(t_stack_node **a);
int				ft_overflow(long long result, int sign, int digit);
void			ft_handle_sign(const char *input_args, int *i, int *sign);
void			ft_free_args_split_stack_exit(char **args_split,
					t_stack_node **a, int exit_flag);
#endif
