/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:21:08 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/15 15:59:36 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
}

/**
 * @brief Pruebas
 * 
 * @param argc 
 * @param params 
 */
void	init_stacks(int argc, char **params)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*a;
	t_node	*b;

	stack_a = init_node_and_check(argc, params);
	stack_b = NULL;
	a = stack_a;
	b = stack_b;
	int count = count_nodes(a);
	if (count < 4)
		//sort_3(&stack_a);
	if (count > 3)
		printf("count %i\n", count);
	//leave_only3(&stack_a, &stack_b, count);
	//sort_3(&stack_a);
	ft_get_pos(a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	ft_push_a(&b, &a);
	rotate_a(&a, 1);
	// ft_push_a(&b, &a);
	// ft_push_a(&b, &a);
	// ft_push_a(&b, &a);
	//leave_only3(&a, &b, count_nodes(a));
	ft_get_pos(a);
	ft_get_pos(b);
	search_target(&a, &b);
	cost_b(&b);
	cost_a(&a, &b);
	//total_cost(&b);
	lower_cost(&b);
	
	printf("stack_b----------------------\n");
	// ft_get_pos(stack_b);
	while (b)
	{
		printf("idx = %i       ", b->idx);
		//printf("value = %i        ", b->value);
		//printf("pos = %i        ", b->pos);
		printf("target = %i        ", b->target);
		printf("cost_b = %i      ", b->cost_b);
		printf("cost_a = %i      ", b->cost_a);
		printf("total_cost = %i\n", b->total_cost);
		free(b);
		b = b->next;
	}
	printf("stack_a----------------------\n");
	while (a)
	{
		printf("idx = %i ", a->idx);
		printf("value = %i ", a->value);
		printf("pos = %i\n", a->pos);
		free(a);
		a = a->next;
	}
	printf("\n");
	printf("stack_b\n");
	while (b)
	{
		printf("value = %i ", b->value);
		printf("pos = %i\n", b->pos);
		free(b);
		b = b->next;
	}
}

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
		argc = ft_count_num(params[1]);
		node_a = save_matrix_node_a(argc, matrix);
		free(matrix);
	}
	if (count_nodes(node_a) < 2)
		help_argv_validate("No hay numeros para ordenar");
	is_repeat_nbr(node_a);
	ft_get_pos(node_a);
	ft_get_idx(&node_a);
	return (node_a);
}

int	main(int argc, char **argv)
{
	//atexit(leaks);
	init_stacks(argc, argv);
	return (0);
}
