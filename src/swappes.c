/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:58:14 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 20:32:22 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_swap_a(t_node **stack_a, int mute)
{
	t_node	*tmp;

	tmp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	if (!mute)
		ft_printf("sa\n");
}

void	ft_move_swap_b(t_node **stack_b, int mute)
{
	ft_move_swap_a(stack_b, 1);
	if (!mute)
		ft_printf("sb\n");
}

void	ft_move_swap_ab(t_node **stack_a, t_node **stack_b)
{
	ft_move_swap_a(stack_a, 1);
	ft_move_swap_b(stack_b, 1);
	ft_printf("ss\n");
}
