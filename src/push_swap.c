/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:21:08 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/01 11:28:24 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;
	//atexit(leaks);
	stack_a = init_node_and_check(argc, argv);
	stack_b = NULL;
	count = count_nodes(stack_a);
	if (count < 4)
		sort_3(&stack_a);
	if (count > 3)
	{	
		leave_only3(&stack_a, &stack_b, count);
		sort_3(&stack_a);
		stack_a = order(&stack_a, &stack_b);
	}
	free_node(stack_b);
	free_node(stack_a);
	return (0);
}
