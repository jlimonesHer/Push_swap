/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 08:31:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/21 12:11:09 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/**
 * @brief esta funcion creara un nuevo nodo al principio de la lista
 * 
 * @param node recibe un puntero al puntero de la lista
 * @param num el entero a guardar,
 */
void	ft_push(t_node **node, int value, int idx)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!node)
		std_error("Algo salio mal al reservar memoria");
	new_node->value = value;
	new_node->idx = idx;
	new_node->target = 0;
	new_node->cost_b = 0;
	new_node->cost_a = 0;
	new_node->total_cost = 0;
	new_node->next = *node;
	*node = new_node;
}

/**
 * @brief Cambia un nodo de stack
 * 
 * @param node pila actual del nodo a cambiar
 * @param dst destino del nodo
 * @param stack pila de destino
 */
void	ft_push_b(t_node **dst, t_node **node)
{
	t_node	*a;

	if ((*node) == NULL)
		return ;
	a = *node;
	ft_push(dst, a->value, a->idx);
	*node = a->next;
	printf("pa\n");
}

void	ft_push_a(t_node **dst, t_node **node)
{
	t_node	*a;

	if ((*node) == NULL)
		return ;
	a = *node;
	ft_push(dst, a->value, a->idx);
	*node = a->next;
	free(a);
	printf("pb\n");
}
