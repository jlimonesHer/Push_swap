/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:21:08 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/13 12:20:13 by jlimones         ###   ########.fr       */
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
	//t_node	*tmp_a;
	//t_node	*tmp_b;

	stack_a = init_node_and_check(argc, params);
	stack_b = NULL;
	int count = count_nodes(stack_a);
	if (count < 4)
		//sort_3(&stack_a);
	if (count > 3)
	printf("count %i\n", count);
		sort_100(&stack_a, &stack_b, count);
	printf("stack_b----------------------\n");
	while (stack_b)
	{
		printf("idx = %i ", stack_b->idx);
		printf("value = %i ", stack_b->value);
		printf("pos = %i ", stack_b->pos);
		printf("target = %i\n", stack_b->target);
		stack_b = stack_b->next;
		//free(stack_b);
	}
	printf("stack_a----------------------\n");
	while (stack_a)
	{
		printf("idx = %i ", stack_a->idx);
		printf("value = %i ", stack_a->value);
		printf("pos = %i\n", stack_a->pos);
		stack_a = stack_a->next;
		free(stack_a);
	}
	printf("\n");
	printf("stack_b\n");
	while (stack_b)
	{
		printf("value = %i ", stack_b->value);
		printf("pos = %i\n", stack_b->pos);
		stack_b = stack_b->next;
		free(stack_b);
	}
}

/**
 * @brief Inicializa las dos pilas:
 * 			En a se asigna el valor, el indice y la posicion
 * @param argc numero de arumentos
 * @param params argumentos
 * @return void* retorna el puntero al primer nodo de la pila
 */
void	*init_node_and_check(int argc, char **params)
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
