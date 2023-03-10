/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:58:14 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/02 10:28:36 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/**
 * @brief intercambia los dos primeros elementos encima del node a
 * 
 * @param stack_a pila a
 * @param mute true o false
 */
void	ft_move_swap_a(t_node **stack_a, int mute)
{
	t_node	*tmp;

	if ((*stack_a) == NULL || count_nodes(*stack_a) < 2)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	if (!mute)
		ft_printf("sa\n");
}

/**
 * @brief intercambia los dos primeros elementos encima del node b
 * 
 * @param stack_a pila b
 * @param mute true o false
 */
void	ft_move_swap_b(t_node **stack_b, int mute)
{
	ft_move_swap_a(stack_b, 1);
	if (!mute)
		ft_printf("sb\n");
}

/**
 * @brief intercambia los dos primeros elementos encima del node a y b
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 */
void	ft_move_swap_ab(t_node **stack_a, t_node **stack_b)
{
	ft_move_swap_a(stack_a, 1);
	ft_move_swap_b(stack_b, 1);
	ft_printf("ss\n");
}
