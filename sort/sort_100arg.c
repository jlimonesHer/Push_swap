/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:41:31 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/13 16:16:06 by jlimones         ###   ########.fr       */
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

void	search_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmpb;
	int		i;

	i = 0;
	tmp = (*stack_a);
	tmpb = (*stack_b);
	while (tmp)
	{
		
	}
}

void	get_target_pos(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmpb;
	int		count;
	int		diff;

	count = 0;
	tmp = (*stack_a);
	tmpb = (*stack_b);
	while (tmpb)
	{
		while (tmp)
		{
			if (tmp->idx > count)
				count = tmp->idx;
			tmp = tmp->next;
		}
	printf("pos target = %i\n", tmpb->target);
}

void	sort_100(t_node **stack_a, t_node **stack_b, int count)
{
	leave_only3(stack_a, stack_b, count);
	ft_get_pos(*stack_a);
	ft_get_pos(*stack_b);
	printf("value= %i\n", (*stack_a)->idx);
	printf("value= %i\n", (*stack_b)->idx);
	get_target_pos(stack_a, stack_b);
}
