/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:23:07 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/02 15:35:34 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

/**
 * @brief Esta es la estructura que utilizaremos para guardar los nodos 
 * de la node 
 * @date value -> guardara el valor del nodo
 * @date idx -> indice en la lista de todos los valores que deben ordenarse
 * @date pos -> posicion actual en su pila
 * @date target -> para elementos en la pila b, posicion donde deberia ir en 
 * la pila a
 * @date cost_a -> coste rotaciones para que llegue a la posicion superior 
 * de la pila a
 * @date cost_a -> coste rotaciones para que llegue a la posicion superior 
 * de la pila b
 */
typedef struct s_node
{
	int				value;
	int				idx;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_node	*next;
}	t_node;

/* init_free_display.c */
t_node		*init_node_and_check(int argc, char **params, int is_checker);
void		free_node(t_node *stack);
void		leaks(void);
void		print_stack(t_node *stack);

/* save_num.c */
int			ft_count_num(char **params);
t_node		*save_matrix_node_a(int argc, char **params);
t_node		*save_param_node_a(int argc, char **params);

/* check_params.c */
int			is_num_or_signed(char param);
int			check_param_num(int argc, char **params, int one_param);
char		**split_for_param(char *params);
int			is_repeat_nbr(t_node *node_a);
void		control_atoi(char *n);

/* get_data_struck.c */
int			count_nodes(t_node *list);
void		help_argv_validate(char *error);
void		std_error(char *error);
void		ft_get_pos(t_node *node);
void		ft_get_idx(t_node **node);

/* swpappes.c */
void		ft_move_swap_a(t_node **stack_a, int mute);
void		ft_move_swap_b(t_node **stack_b, int mute);
void		ft_move_swap_ab(t_node **stack_a, t_node **stack_b);

/* push.c */
void		ft_push(t_node **node, int value, int idx);
void		push_b(t_node **dst, t_node **node, int mute);
void		push_a(t_node **dst, t_node **node, int mute);

/* rotate.c */
void		rotate_a(t_node **stack_a, int mute);
void		rotate_b(t_node **stack_b, int mute);
void		rotate_ab(t_node **stack_a, t_node **stack_b, int mute);

/* reverse_rotate.c */
void		reverse_rotate_a(t_node **stack_a, int mute);
void		reverse_rotate_b(t_node **stack_b, int mute);
void		reverse_rotate_ab(t_node **stack_a, t_node **stack_b, int mute);

/* sort_3.c */
void		sort_3(t_node **stack_a);

/* cal_target.c */
void		leave_only3(t_node **stack_a, t_node **stack_b, int count);
int			idx_min(t_node **stack_a);
void		search_target(t_node **stack_a, t_node **stack_b);

/* cost.c */
void		cost_b(t_node **stack_b);
void		cost_a(t_node **stack_a, t_node **stack_b);
void		total_cost(t_node **stack_b);
t_node		*lower_cost(t_node **stack_b);
void		recalculate(t_node **a, t_node **b);

/* order.c */
void		end_move(t_node **stack_a);
void		a_pos_b_neg(t_node **stack_a, t_node **stack_b, t_node *lower);
void		a_neg_b_pos(t_node **stack_a, t_node **stack_b, t_node *lower);
void		a_b_neg(t_node **stack_a, t_node **stack_b, t_node *lower);
void		a_b_pos(t_node **stack_a, t_node **stack_b, t_node *lower);

/* algorithm.c */
t_node		*order(t_node **stack_a, t_node **stack_b);

/* check_ordered_num.c */
void		ordered_number(t_node **stack);
void		minus_number(t_node **stack, int count);

int			sort_number(t_node **lst);
int			sort_number2(t_node **lst);
void		free_node(t_node *stack);

void		print_stack(t_node *stack);
#endif
