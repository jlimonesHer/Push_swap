/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:21:08 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/12 09:41:45 by jlimones         ###   ########.fr       */
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
	//tmp_a = stack_a;
	ft_push_a(&stack_b, &stack_a);
	//ft_push_a(&stack_b, &stack_a);
	//ft_push_a(&stack_b, &stack_a);
	//ft_push_a(&stack_b, &stack_a);
	//ft_push_a(&stack_b, &stack_a);
	// ft_push_a(&stack_b, &stack_a);
	// ft_push_a(&stack_b, &stack_a);
	// ft_push_a(&stack_b, &stack_a);
	ft_push_b(&stack_a, &stack_b);
	// ft_push_b(&stack_a, &stack_b);
	//ft_push_b(&stack_a, &stack_b);
	//ft_push_b(&stack_a, &stack_b);
	//tmp_b = stack_b;
	printf("stack_b----------------------\n");
	while (stack_b)
	{
		printf("%i ", stack_b->value);
		//printf("nodesb = %i\n", nodes_b->idx);
		//printf("nodesb = %i\n", nodes_b->pos);
		stack_b = stack_b->next;
		//free(stack_b);
	}
	printf("\n");
	//stack_b = tmp_b;
	ft_move_swap_a(&stack_a, 0);
	ft_move_swap_b(&stack_b, 0);
	ft_move_swap_ab(&stack_a, &stack_b);
	rotate_a(&stack_a, 0);
	rotate_b(&stack_b, 0);
	//ft_push_b(&stack_a, &stack_b);
	rotate_ab(&stack_a, &stack_b);
	reverse_rotate_a(&stack_a, 0);
	reverse_rotate_b(&stack_a, 0);
	reverse_rotate_ab(&stack_a, &stack_b);
	//stack_a = tmp_a;
	//printf("stack_a %i\n", stack_a->value);
	printf("stack_a----------------------\n");
	while (stack_a)
	{
		printf("pos = %i ", stack_a->pos);
		printf("value = %i\n", stack_a->value);
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
	atexit(leaks);
	init_stacks(argc, argv);
	return (0);
}
