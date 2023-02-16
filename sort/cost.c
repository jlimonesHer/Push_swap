/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:11:28 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/16 17:58:26 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/**
 * @brief calcula el coste para llevarlo a la primera posicion de la pila b
 * 
 * @param stack_b pila b
 */
void	cost_b(t_node **stack_b)
{
	t_node	*b;
	int		len;

	b = *stack_b;
	len = count_nodes(b) / 2;
	while (b)
	{
		if (b->pos <= len)
			b->cost_b = b->pos;
		else if (b->pos > len)
			b->cost_b = (len * 2 - b->pos + 1) * -1;
		b = b->next;
	}
}

/**
 * @brief calcula el coste para llevarlo a la primera posicion de la pila a
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 */
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
				if (a->pos <= len)
					b->cost_a = a->pos;
				else if (a->pos > len)
					b->cost_a = (len * 2 - a->pos) * -1;
			}
			a = a->next;
		}
		b = b->next;
	}
}

/**
 * @brief calcula el coste de cada nodo para llevarlo a la posicion objetivo 
 * en la pila a
 * 
 * @param stack_b 
 */
void	total_cost(t_node **stack_b)
{
	t_node	*b;

	b = *stack_b;
	while (b)
	{
		if (b->cost_a >= 0 && b->cost_b >= 0)
		{
			if (b->cost_a > b->cost_b)
				b->total_cost = b->cost_a;
			else
				b->total_cost = b->cost_b;
		}
		else if (b->cost_a < 0 && b->cost_b < 0)
		{
			if (b->cost_a < b->cost_b)
				b->total_cost = b->cost_a * -1;
			else
				b->total_cost = b->cost_b * -1;
		}
		else
			b->total_cost = b->cost_a - b->cost_b;
		if (b->total_cost < 0)
			b->total_cost *= -1;
		b = b->next;
	}	
}

/**
 * @brief 
 * 
 * @param stack_b 
 * @return t_node* 
 */
int	lower_cost(t_node **stack_b)
{
	t_node	*b;
	int		cost;

	b = *stack_b;
	cost = INT_MAX;
	total_cost(stack_b);
	while (b)
	{
		if (b->total_cost < cost)
		{
			cost = b->total_cost;
			printf("cost = %i\n", b->total_cost);
		}
		b = b->next;
	}
	return (cost);
}
