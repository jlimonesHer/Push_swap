/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:11:28 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/22 12:25:03 by jlimones         ###   ########.fr       */
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
	//printf("entra en cost b -> %i\n", (*stack_b)->idx);
	while (b)
	{
		if (b->pos <= len)
			b->cost_b = b->pos;
		else if (b->pos > len)
			b->cost_b = (len * 2 - b->pos + 1) * -1;
		b = b->next;
	}
	//printf("sale en cost b -> %i, costb = %i\n", (*stack_b)->idx, (*stack_b)->cost_b);
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
	while (b)
	{
		if (b->target > len / 2)
			if (len % 2)
				len--;
			b->cost_a = b->target - (len) - 1;
		if (b->target <= len)
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
int	lower_cost(t_node **stack_b)
{
	t_node	*b;
	int		i;
	int		len;

	b = *stack_b;
	i = -1;
	len = count_nodes(b);
	total_cost(&b);
	while (b && ++i != b->total_cost && len >= 0)
	{
		if (!b->next)
			return (0);
			b = b->next;
		if (b->total_cost == i)
			return (b->idx);
		else if (!b)
		{
			b = *stack_b;
			i++;
		}
	}
	return (b->idx);
}

void	recalculate(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;

	b = (*stack_b);
	a = (*stack_a);
	ft_get_pos(a);
	ft_get_pos(b);
	search_target(&a, &b);
	cost_b(&b);
	cost_a(&a, &b);
	total_cost(&b);
	ft_get_pos(a);
	ft_get_pos(b);
}
