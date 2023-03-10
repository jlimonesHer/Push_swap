/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:48:44 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/01 17:18:18 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_node	*order(t_node **stack_a, t_node **stack_b)
{
	t_node	*lower;

	while (*stack_b)
	{
		recalculate(stack_a, stack_b);
		lower = lower_cost(stack_b);
		if (lower->cost_b >= 0 && lower->cost_a >= 0)
			a_b_pos(stack_a, stack_b, lower);
		else if (lower->cost_b < 0 && lower->cost_a < 0)
			a_b_neg(stack_a, stack_b, lower);
		else if (lower->cost_b >= 0 && lower->cost_a < 0)
			a_neg_b_pos(stack_a, stack_b, lower);
		else if (lower->cost_b < 0 && lower->cost_a >= 0)
			a_pos_b_neg(stack_a, stack_b, lower);
	}
	ft_get_pos(*stack_a);
	end_move(stack_a);
	return (*stack_a);
}
