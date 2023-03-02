/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 08:31:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/02 15:35:34 by jlimones         ###   ########.fr       */
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

	new_node = ft_calloc(1, sizeof(t_node));
	if (!node)
		std_error("Error");
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
void	push_a(t_node **dst, t_node **node, int mute)
{
	t_node	*a;

	if ((*node) == NULL)
		return ;
	a = *node;
	ft_push(dst, a->value, a->idx);
	*node = a->next;
	free(a);
	if (!mute)
		ft_printf("pa\n");
}

void	push_b(t_node **dst, t_node **node, int mute)
{
	t_node	*a;

	if ((*node) == NULL)
		return ;
	a = *node;
	ft_push(dst, a->value, a->idx);
	*node = a->next;
	free(a);
	if (!mute)
		ft_printf("pb\n");
}
