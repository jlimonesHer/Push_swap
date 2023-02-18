/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:46:20 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/16 20:32:49 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	a_b_pos(t_node **stack_a, t_node **stack_b, int cost)
{
	if ((*stack_b)->cost_b == 0 && (*stack_b)->cost_a == 0)
		ft_push_b(stack_a, stack_b);
	while ((*stack_b)->cost_b > 0 && (*stack_b)->cost_a > 0)
	{
		reverse_rotate_ab(stack_a, stack_b);
		(*stack_b)->cost_b--;
		(*stack_b)->cost_a--;
	}
	if ((*stack_b)->cost_b >= 0 || (*stack_b)->cost_a >= 0)
	{
		if ((*stack_b)->cost_b >= 0)
		{
			reverse_rotate_b(stack_b, 0);
			(*stack_b)->cost_b--;
		}
		else if ((*stack_b)->cost_a >= 0)
		{
			reverse_rotate_a(stack_a, 0);
			(*stack_b)->cost_a--;
		}
	}
	if (cost == (*stack_a)->total_cost)
		ft_push_b(stack_a, stack_b);
}

void	a_b_neg(t_node **stack_a, t_node **stack_b, int cost)
{
	while ((*stack_b)->cost_b < 0 && (*stack_b)->cost_a < 0)
	{
		rotate_ab(stack_a, stack_b);
		(*stack_b)->cost_b++;
		(*stack_b)->cost_a++;
	}
	if ((*stack_b)->cost_b < 0 || (*stack_b)->cost_a < 0)
	{
		if ((*stack_b)->cost_b < 0)
		{
			rotate_b(stack_b, 0);
			(*stack_b)->cost_b++;
		}
		else if ((*stack_b)->cost_a < 0)
		{
			rotate_a(stack_a, 0);
			(*stack_b)->cost_a++;
		}
	}
	if (cost == (*stack_a)->total_cost)
		ft_push_b(stack_a, stack_b);
}

void	a_neg_b_pos(t_node **stack_a, t_node **stack_b, int cost)
{
	if ((*stack_b)->cost_b >= 0 || (*stack_b)->cost_a < 0)
	{
		if ((*stack_b)->cost_b >= 0)
		{
			reverse_rotate_b(stack_b, 0);
			(*stack_b)->cost_b--;
		}
		else if ((*stack_b)->cost_a < 0)
		{
			rotate_a(stack_a, 0);
			(*stack_b)->cost_a++;
		}
	}
	if (cost == (*stack_a)->total_cost)
		ft_push_b(stack_a, stack_b);
}

void	a_pos_b_neg(t_node **stack_a, t_node **stack_b, int cost)
{
	if ((*stack_b)->cost_b < 0 || (*stack_b)->cost_a >= 0)
	{
		if ((*stack_b)->cost_b < 0)
		{
			rotate_a(stack_a, 0);
			(*stack_b)->cost_a++;
		}
		else if ((*stack_b)->cost_a >= 0)
		{
			reverse_rotate_a(stack_a, 0);
			(*stack_b)->cost_a--;
		}
	}
	if (cost == (*stack_a)->total_cost)
		ft_push_b(stack_a, stack_b);
}

void order(t_node **stack_a, t_node **stack_b)
{
	t_node	*b = *stack_b;
	t_node *a = *stack_a;
	int cost = lower_cost(stack_b);
	while (b)
	{
		ft_get_pos(a);
		ft_get_pos(b);
		search_target(&a, &b);
		cost_b(&b);
		cost_a(&a, &b);
		total_cost(&b);
		lower_cost(&a);
		printf("-----aaaaaaaaa-----\n");
		print_stack(a);
		printf("-----bbbbbbbbb----\n");
		print_stack(b);
		// if ((*stack_b)->cost_b == 0 && (*stack_b)->cost_a == 0)
		// 	ft_push_b(stack_a, stack_b);
		if ((*stack_b)->cost_b >= 0 && (*stack_b)->cost_a >= 0)
			a_b_pos(&a, &b, cost);
		else if ((*stack_b)->cost_b < 0 && (*stack_b)->cost_a < 0)
			a_b_neg(&a, &b, cost);
		else if ((*stack_b)->cost_b >= 0 && (*stack_b)->cost_a < 0)
			a_neg_b_pos(&a, &b, cost);
		else if ((*stack_b)->cost_b < 0 && (*stack_b)->cost_a >= 0)
			a_pos_b_neg(&a, &b, cost);
	}
}