/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 08:31:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/11 09:08:03 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/**
 * @brief esta funcion creara un nuevo nodo al principio de la lista
 * 
 * @param node recibe un puntero al puntero de la lista
 * @param num el entero a guardar,
 */
void	ft_push(t_node **node, int value, int idx, int pos)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!node)
		std_error("Algo salio mal al reservar memoria");
	new_node->value = value;
	new_node->idx = idx;
	new_node->pos = pos;
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
void	ft_push_a(t_node **dst, t_node **node, char stack)
{
	t_node	*a;

	if ((*node) == NULL)
		return ;
	a = *node;
	ft_push(dst, a->value, a->idx, a->pos);
	*node = a->next;
	free(a);
	if (stack == 'a')
		printf("pa\n");
	if (stack == 'b')
		printf("pb\n");
}
