/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:11:28 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/14 19:18:00 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	cost_b(t_node **stack_b)
{
	t_node	*b;
	int		len;

	b = *stack_b;
	printf("cost = %i\n", b->cost_b);
	len = count_nodes(b) / 2;
	while (b)
	{
		if (b->pos <= len)
			b->cost_b = b->pos;
		else if (b->pos > len)
			b->cost_b = len * 2 - b->pos + 1;
		b = b->next;
	}
	return (len);
}
