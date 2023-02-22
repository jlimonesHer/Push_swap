/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:11:28 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/22 20:33:21 by jlimones         ###   ########.fr       */
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
	len = count_nodes(b);
	while (b)
	{
		if (b->pos <= len / 2)
			b->cost_b = b->pos;
		else if (b->pos > len / 2)
			b->cost_b = (len - b->pos) * -1;
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
	len = count_nodes(a);
	printf("len = %i, len / 2 %i\n", len, len /2);
	while (b)
	{
		if (b->target > len / 2)
			b->cost_a = b->target - len;
		else if (b->target <= len / 2)
			b->cost_a = b->target;
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
t_node	*lower_cost(t_node **stack_b)
{
	t_node	*b;
	t_node	*retu;

	b = *stack_b;
	retu = b;
	while (b)
	{
		printf("b = %i,  retu = %i\n", b->total_cost, retu->total_cost);
		if (b->total_cost < retu->total_cost)
			retu = b;
		else
			b = b->next;
	}
	return (retu);
}
