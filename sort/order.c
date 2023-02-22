/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:46:20 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/22 20:53:23 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/**
 * @brief mueve una lista cuando su costo a es positivo y b es positivo
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 */
void	a_b_pos(t_node **stack_a, t_node **stack_b, t_node *lower)
{
	printf("entra en a_b_pos\n");
	while (lower->cost_b > 0 && lower->cost_a > 0)
	{
		rotate_ab(stack_a, stack_b);
		lower->cost_b--;
		lower->cost_a--;
	}
	if (lower->cost_b >= 0 || lower->cost_a >= 0)
	{
		while (lower->cost_b == 0 && lower->cost_a > 0)
		{
			rotate_a(stack_a, 0);
			lower->cost_a--;
		}
		while (lower->cost_b > 0)
		{
			rotate_b(stack_b, 0);
			lower->cost_b--;
		}
	}
	ft_push_b(stack_a, stack_b);
}

/**
 * @brief mueve una lista cuando su costo a negativo es y b es negativo
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 */
void	a_b_neg(t_node **stack_a, t_node **stack_b, t_node *lower)
{
	printf("entra en a_b_neg\n");
	while (lower->cost_b < 0 && lower->cost_a < 0)
	{
		rotate_ab(stack_a, stack_b);
		lower->cost_b++;
		lower->cost_a++;
	}
	if (lower->cost_b < 0 || lower->cost_a < 0)
	{
		if (lower->cost_b < 0)
		{
			rotate_b(stack_b, 0);
			lower->cost_b++;
		}
		else if (lower->cost_a < 0)
		{
			rotate_a(stack_a, 0);
			lower->cost_a++;
		}
	}
	ft_push_b(stack_b, stack_b);
}

/**
 * @brief mueve una lista cuando su costo a negativo es y b es positivo
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 */
void	a_neg_b_pos(t_node **stack_a, t_node **stack_b, t_node *lower)
{
	printf("entra en a_neg_b_pos\n");
	if (lower->cost_b >= 0 || lower->cost_a < 0)
	{
		while (lower->cost_b > 0)
		{
			rotate_a(stack_b, 0);
			lower->cost_b--;
		}
		while (lower->cost_a < 0)
		{
			reverse_rotate_a(stack_a, 0);
			lower->cost_a++;
		}
	}
	ft_push_b(stack_a, stack_b);
}

/**
 * @brief mueve una lista cuando su costo a es positico y b es negativo
 * 
 * @param stack_a pila a
 * @param stack_b pila b
 */
void	a_pos_b_neg(t_node **stack_a, t_node **stack_b, t_node *lower)
{
	printf("entra en a_pos_b_neg\n");
	if (lower->cost_b < 0 || lower->cost_a >= 0)
	{
		while (lower->cost_b < 0)
		{
			reverse_rotate_b(stack_b, 0);
			lower->cost_b++;
		}
		while (lower->cost_a > 0)
		{
			rotate_a(stack_a, 0);
			lower->cost_a--;
		}
	}
	ft_push_b(stack_a, stack_b);
}

/**
 * @brief Rota la lista hasta encontrar el numero mas bajo en la primera posicion
 * 
 * @param stack_a pila a
 */
void	end_move(t_node **stack_a)
{
	int		len;
	t_node	*a;

	a = *stack_a;
	len = count_nodes(a);
	while (a && a->idx != 1)
		a = a->next;
	if (a->pos > len / 2)
	{
		while (a->pos < len)
		{
			reverse_rotate_a(stack_a, 0);
			len--;
		}
	}
	else if (a->pos < len / 2 + 1)
	{
		while (a->pos < len / 2)
		{
			rotate_a(stack_a, 0);
			len--;
		}
	}
}
