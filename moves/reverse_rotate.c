/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:38:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/12 08:59:31 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	reverse_rotate_a(t_node **stack_a, int mute)
{
	t_node	*tmp;
	t_node	*end;

	if ((*stack_a) == NULL)
		return ;
	tmp = *stack_a;
	while ((*stack_a)->next->next)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next->next = tmp;
	end = (*stack_a)->next;
	(*stack_a)->next = NULL;
	(*stack_a) = end;
	ft_get_pos((*stack_a));
	if (!mute)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **stack_b, int mute)
{
	reverse_rotate_a(stack_b, 1);
	if (!mute)
		ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a, 1);
	reverse_rotate_b(stack_b, 1);
	ft_printf("rrr\n");
}