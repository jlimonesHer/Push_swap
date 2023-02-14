/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:41:31 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/14 19:09:38 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/**
 * @brief saca la media de los idx de la pila
 * 
 * @param stack_a pila
 * @param count numero de nodos
 * @return int devuelme la media de los idx de la pila
 */
static int	middle(t_node	**stack_a, int count)
{
	t_node	*tmp;
	int		middle;

	tmp = (*stack_a);
	middle = 0;
	while (tmp)
	{
		middle += tmp->idx;
		tmp = tmp->next;
	}
	middle /= count;
	return (middle);
}

/**
 * @brief pushea primero todos los numero con el idx inferior a la media
 * y despues todos los demas.
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 * @param count numero de nodos
 */
//static void	leave_only_3(t_node **stack_a, t_node **stack_b, int count)
void	leave_only3(t_node **stack_a, t_node **stack_b, int count)
{
	t_node	*tmp;
	int		total;

	total = middle(stack_a, count);
	tmp = (*stack_a);
	while (tmp && (count > 0))
	{
		if ((*stack_a)->idx <= total)
		{
			ft_push_b(stack_b, stack_a);
			tmp = (*stack_a);
		}
		else if ((*stack_a)->idx > total)
		{
			rotate_a(stack_a, 1);
			count--;
		}
		else if (tmp->idx == (*stack_a)->idx)
			tmp = tmp->next;
	}
	tmp = (*stack_a);
	count = count_nodes(*stack_a) + 1;
	while (--count > 3)
		ft_push_b(stack_b, stack_a);
	sort_3(stack_a);
}

/**
 * @brief busca el indice menor para colocar los numero con mayor 
 * indice de la pila b que en la pila a
 * 
 * @param stack_a pila en la que buscar el menor indice
 * @return int 
 */
int	idx_min(t_node **stack_a)
{
	t_node	*tmp;
	int		idx_min;

	tmp = (*stack_a);
	idx_min = INT_MAX;
	while (tmp)
	{
		if (tmp->idx < idx_min)
			idx_min = tmp->pos;
		tmp = tmp->next;
	}
	return (idx_min);
}

/**
 * @brief busca el target de los nodos de la pila b
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 */
void	search_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;
	int		min;

	min = idx_min(stack_a);
	a = (*stack_a);
	b = (*stack_b);
	while (b)
	{
		b->target = INT_MAX;
		while (a)
		{
			if (a->idx > b->idx && a->idx < b->target)
				b->target = a->pos;
		a = a->next;
		}
		if (b->target == INT_MAX)
			b->target = min;
		b = b->next;
		a = (*stack_a);
	}
}
