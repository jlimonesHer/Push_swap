/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:41:31 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/13 11:32:22 by jlimones         ###   ########.fr       */
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
void	sort_100(t_node **stack_a, t_node **stack_b, int count)
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

// void	sort_100(t_node **stack_a, t_node **stack_b, int count)
// {
	
// }