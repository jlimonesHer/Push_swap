/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:20:15 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/11 12:54:02 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	rotate_a(t_node **stack_a, char stack)
{
	t_node	*first;
	t_node	*end;

	end = (*stack_a);
	first = (*stack_a)->next;
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->pos--;
	}
	(*stack_a)->next = end;
	(*stack_a)->next->next = NULL;
	(*stack_a)->next->pos = count_nodes(first);
	(*stack_a) = first;
	if (stack == 'a')
		ft_printf("ra\n");
	if (stack == 'b')
		ft_printf("rb\n");
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a, 'c');
	rotate_a(stack_b, 'c');
	ft_printf("rr\n");
}