/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmid <cschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:20:11 by cschmid           #+#    #+#             */
/*   Updated: 2024/05/30 14:08:37 by cschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# define INTMIN -2147483648
# define INTMAX 2147483647

typedef struct stack_node
{
	int					nbr;
	int					indice;
	int					cost;
	int					total_cost;
	int					cheap;
	int					median;
	int					median_a;
	int					median_b;

	struct stack_node	*target_node;
	struct stack_node	*next;
	struct stack_node	*prev;
}						t_stack_node;

// Operations
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);

void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);

void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);

// Parsing
int						check_digit(int argc, char **argv);
int						check_double(int argc, char **argv);
int						z_overflow(char **argv);
int						check_sign(int argc, char **argv);
int						parsing_quote(int argc, char **argv);
int						ft_errors(int argc, char **argv);
int						parsing_arg(int argc, char **argv);
void					free_split(char **split);

// utils
t_stack_node			*cheap_node(t_stack_node *x);
void					top_cost(t_stack_node *x);
void					bot_cost(t_stack_node *x);
t_stack_node			*find_max(t_stack_node *x);
t_stack_node			*find_last(t_stack_node *stack);
void					indice(t_stack_node **x);
void					current_index(t_stack_node *x);
int						find_median(t_stack_node *x);
void					init_stack_a(t_stack_node **a, char **argv);
void					init_stack_a_to(t_stack_node **a, char **argv);
void					ft_free(char **f);
void					find_target(t_stack_node *a, t_stack_node *b);
void					total_cost(t_stack_node *a);
void					free_stack(t_stack_node *stack);
void					free_all(t_stack_node **a, t_stack_node **b);
t_stack_node			*find_min(t_stack_node *stack);
void					add_node_to_end(t_stack_node **list,
							t_stack_node *node);
t_stack_node			*create_node(int n, int i);
void					add_node(t_stack_node **a, int n, int i);
int						count_stack(t_stack_node *stack);

// sort
void					sort_stack(t_stack_node **a, t_stack_node **b);
void					gestion_cost(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					prep_for_push(t_stack_node **tmp,
							t_stack_node *node_cheap, char stack);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					sort_a_to_b(t_stack_node **a, t_stack_node **b);
void					sort_b_to_a(t_stack_node **a, t_stack_node **b);
void					min_on_top(t_stack_node **x);
void					sort_three(t_stack_node **a);
int						ft_errors_split(int argc, char **split);
int						stack_sorted(t_stack_node *stack);

#endif