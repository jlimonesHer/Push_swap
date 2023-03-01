/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:27:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/01 11:28:17 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Inicializa las dos pilas:
 * 			En a se asigna el valor, el indice y la posicion
 * @param argc numero de arumentos
 * @param params argumentos
 * @return void* retorna el puntero al primer nodo de la pila
 */
t_node	*init_node_and_check(int argc, char **params)
{
	t_node	*node_a;
	char	**matrix;

	if (argc > 2)
	{
		check_param_num(argc, params);
		node_a = save_param_node_a(argc, params);
	}
	else
	{
		matrix = split_for_param(params[1]);
		argc = ft_count_num(matrix);
		node_a = save_matrix_node_a(argc, matrix);
		free(matrix);
		free(matrix[argc - 1]);
	}
	if (count_nodes(node_a) < 3)
		minus_number(&node_a, count_nodes(node_a));
	is_repeat_nbr(node_a);
	ft_get_pos(node_a);
	ft_get_idx(&node_a);
	return (node_a);
}

void	free_node(t_node *stack)
{
	while (stack)
	{
		free(stack);
		stack = stack->next;
	}
}

void	leaks(void)
{
	system("leaks push_swap");
}

void	print_stack(t_node *stack)
{
	t_node	*b;

	b = stack;
	while (b)
	{
		printf("idx = %i       ", b->idx);
		printf("value = %i        ", b->value);
		printf("pos = %i        ", b->pos);
		printf("target = %i        ", b->target);
		printf("cost_b = %i      ", b->cost_b);
		printf("cost_a = %i      ", b->cost_a);
		printf("total_cost = %i\n", b->total_cost);
		b = b->next;
	}
}
