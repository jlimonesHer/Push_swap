/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:20:15 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/12 08:59:20 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/**
 * @brief rota 1 posicion hacia arriba la pila a
 * 
 * @param stack_a puntero a puntero de la pila a mover
 * @param mute true o false
 */
void	rotate_a(t_node **stack_a, int mute)
{
	t_node	*first;
	t_node	*end;

	if ((*stack_a) == NULL)
		return ;
	end = (*stack_a);
	first = (*stack_a)->next;
	while ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = end;
	(*stack_a)->next->next = NULL;
	(*stack_a)->next->pos = count_nodes(first);
	(*stack_a) = first;
	ft_get_pos((*stack_a));
	if (!mute)
		ft_printf("ra\n");
}

/**
 * @brief rota 1 posicion hacia arriba la pila b
 * 
 * @param stack_a puntero a puntero de la pila a mover
 * @param mute true o false
 */
void	rotate_b(t_node **stack_b, int mute)
{
	rotate_a(stack_b, 0);
	if (!mute)
		ft_printf("rb\n");
}

/**
 * @brief rota 1 posicion hacia arriba las dos pilas
 * 
 * @param stack_a puntero a puntero de la pila a mover
 * @param stack_b puntero a puntero de la pila a mover
 */
void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	ft_printf("rr\n");
}
