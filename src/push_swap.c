/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:21:08 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/24 19:35:54 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
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
		argc = ft_count_num(matrix);
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

void	free_node(t_node *stack)
{
	while (stack)
	{
		free(stack);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;
	atexit(leaks);
	stack_a = init_node_and_check(argc, argv);
	stack_b = NULL;
	count = count_nodes(stack_a);
	if (count < 4)
		sort_3(&stack_a);
	if (count > 3)
	{	
		leave_only3(&stack_a, &stack_b, count);
		sort_3(&stack_a);
		stack_a = order(&stack_a, &stack_b);
	}
	free_node(stack_b);
	free_node(stack_a);
	return (0);
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
