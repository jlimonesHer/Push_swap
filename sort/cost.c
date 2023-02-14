/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:11:28 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/14 22:31:12 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	cost_b(t_node **stack_b)
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
}

void	cost_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;
	int		len;

	b = *stack_b;
	a = *stack_a;
	len = count_nodes(a) / 2;
	while (b)
	{
		a = *stack_a;
		while (a)
		{
			if (a->pos == b->target)
			{
				printf("len %i Y pos = %i\n", len, a->pos);
				if (a->pos <= len)
					b->cost_a = a->pos;
				else if (a->pos > len)
					b->cost_a = len * 2 - a->pos;
			}
			a = a->next;
		}
		b = b->next;
	}
}
