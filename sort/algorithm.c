/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:48:44 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/22 19:54:39 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"



t_node	*order(t_node **stack_a, t_node *b)
{
	t_node	*a;
	t_node	*lower;

	a = *stack_a;
	while (b)
	{
	recalculate(&a, &b);
	lower = lower_cost(&b);
	printf("lower = %i--------------------------------------\n", lower->idx);
	printf("antes\n");
	printf("-------a---------\n");
	print_stack(a);
	printf("-------b---------\n");
	print_stack(b);
		if (lower->cost_b >= 0 && lower->cost_a >= 0)
			a_b_pos(&a, &b, lower);
		else if (lower->cost_b < 0 && lower->cost_a < 0)
			a_b_neg(&a, &b, lower);
		else if (lower->cost_b >= 0 && lower->cost_a < 0)
			a_neg_b_pos(&a, &b, lower);
		else if (lower->cost_b < 0 && lower->cost_a >= 0)
			a_pos_b_neg(&a, &b, lower);
	printf("despues\n");
	printf("-------a---------\n");
	print_stack(a);
	printf("-------b---------\n");
	print_stack(b);
	printf("-------b---------\n\n\n");
	}
	ft_get_pos((a));
	end_move(&a);
	return (a);
}