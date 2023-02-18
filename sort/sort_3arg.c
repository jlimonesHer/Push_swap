/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:27 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/16 19:31:11 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	sort_3(t_node **stack_a)
{
		printf("1 = %i 2 = %i 3 = %i\n", (*stack_a)->idx, (*stack_a)->next->idx, (*stack_a)->next->next->idx);
	if ((*stack_a)->idx < (*stack_a)->next->idx
		&& (*stack_a)->next->idx < (*stack_a)->next->next->idx)
		return ;
	else if ((*stack_a)->idx < (*stack_a)->next->idx
		&& (*stack_a)->next->idx > (*stack_a)->next->next->idx)
	{
		reverse_rotate_a(stack_a, 0);
		ft_move_swap_a(stack_a, 0);
	}
	else if ((*stack_a)->idx > (*stack_a)->next->idx
		&& (*stack_a)->idx < (*stack_a)->next->next->idx)
		ft_move_swap_a(stack_a, 0);
	else if ((*stack_a)->idx > (*stack_a)->next->idx
		&& (*stack_a)->next->idx < (*stack_a)->next->next->idx)
		reverse_rotate_a(stack_a, 0);
	else if ((*stack_a)->idx > (*stack_a)->next->idx
		&& (*stack_a)->next->idx < (*stack_a)->next->next->idx)
		rotate_a(stack_a, 0);
	else if ((*stack_a)->idx > (*stack_a)->next->idx
		&& (*stack_a)->next->idx > (*stack_a)->next->next->idx)
	{
		rotate_a(stack_a, 0);
		ft_move_swap_a(stack_a, 0);
	}
}
