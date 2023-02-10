/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:23:07 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 12:31:24 by jlimones         ###   ########.fr       */
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
	int				pos_init;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

void		*init_node_and_check(int argc, char **params);
int			is_num_or_signed(char param);
int			check_param_num(int argc, char **params);
char		**split_for_param(char *params);
int			ft_count_num(char *params);
void		help_argv_validate(char *error);
void		std_error(char *error);
void		ft_push(t_node **node, int num);
t_node		*save_matrix_node_a(int argc, char **params);
t_node		*save_param_node_a(int argc, char **params);
int			is_repeat_nbr(t_node *node_a);
void		control_atoi(char *n);
void		ft_get_pos(t_node *node);
void		ft_get_idx(t_node **node);
void		init_stacks(int argc, char **params);
#endif
