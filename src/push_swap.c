/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:21:08 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/20 11:49:20 by jlimones         ###   ########.fr       */
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
	t_node	**a;
	t_node	*b;

	stack_a = init_node_and_check(argc, params);
	stack_b = NULL;
	a = &stack_a;
	b = stack_b;
	int count = count_nodes(*a);
	if (count < 4)
		sort_3(a);
//	if (count > 3)
	a = &stack_a;
	leave_only3(a, &b, count);
	// ft_push_a(&b, &a);
	// ft_push_a(&b, &a);
	// ft_push_a(&b, &a);
	// ft_push_a(&b, &a);
	// ft_push_a(&b, &a);
	//ft_push_a(&b, &a);
	// printf("stack_b------------leave-----\n");
	// print_stack(b);
	sort_3(a);
	// ft_get_pos(a);
	// ft_get_pos(b);
	// printf("stack_b-------------sort-----\n");
	// print_stack(b);
	// printf("stack_b--------target-----------\n");
	// search_target(&a, &b);
	// print_stack(b);
	// printf("stack_b-----------cost_----------\n");
	// cost_a(&a, &b);
	// cost_b(&b);
	// print_stack(b);
	// printf("stack_b--------total_cost-----------\n");
	// total_cost(&b);
	// print_stack(b);
	// printf("stack_a----------------------\n");
	// print_stack(a);
	// printf("stack_b--------ab_pos-----------\n");
	order(a, &b);

	printf("stack_a----------------------\n");
	print_stack(stack_a);

	// printf("stack_b----------------------\n");
	// print_stack(stack_b);
	//printf("\n");
	// printf("stack_a______________________\n");
	// print_stack(a);
	
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

void free_node(t_node *stack)
{
	while (stack)
	{
		printf("free idx = %i\n", stack->idx);
		stack = stack->next;
		free(stack);
	}
}

void print_stack(t_node *stack)
{
	t_node *b = stack;

	if (!b)
		return;
	while (b)
	{
		printf("idx = %i       ", b->idx);
		printf("value = %i        ", b->value);
		printf("pos = %i        ", b->pos);
		printf("target = %i        ", b->target);
		printf("cost_b = %i      ", b->cost_b);
		printf("cost_a = %i      ", b->cost_a);
		printf("total_cost = %i\n", b->total_cost);
		//free(b);
		b = b->next;
	}
}
