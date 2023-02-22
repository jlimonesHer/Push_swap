/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:46:20 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/21 20:34:26 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"


void	a_b_pos(t_node **stack_a, t_node **stack_b)
{
	t_node	**a;

			//printf("entra en a_b_pos idx = %i\n", (*stack_b)->idx);
	a = stack_a;
	while ((*stack_b)->cost_b > 0 && (*stack_b)->cost_a > 0)
	{
		reverse_rotate_ab(stack_a, stack_b);
		(*stack_b)->cost_b--;
		(*stack_b)->cost_a--;
	}
	if ((*stack_b)->cost_b >= 0 || (*stack_b)->cost_a >= 0)
	{
		//printf("entra el numero %i\n", (*stack_b)->idx);
		while ((*stack_b)->cost_b == 0 && (*stack_b)->cost_a > 0)
		{
			rotate_a(stack_a, 0);
			(*stack_b)->cost_a--;
		}
		while ((*stack_b)->cost_b > 0)
		{
			reverse_rotate_b(stack_b, 0);
			(*stack_b)->cost_b--;
		}
	}
	ft_push_b(stack_a, stack_b);
		stack_a = a;
}

void	a_b_neg(t_node **stack_a, t_node **stack_b, int cost)
{
			//printf("entra en a_b_neg\n");
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
		ft_push_b(stack_b, stack_b);
}

void	a_neg_b_pos(t_node **stack_a, t_node **stack_b, int cost)
{//printf("entra en a_neg_b_pos\n");
	if ((*stack_b)->cost_b >= 0 || (*stack_b)->cost_a < 0)
	{
		while ((*stack_b)->cost_b >= 0)
		{
			rotate_b(stack_b, 0);
			(*stack_b)->cost_b--;
		}
		while ((*stack_b)->cost_a < 0)
		{
			reverse_rotate_a(stack_a, 0);
			(*stack_b)->cost_a++;
		}
	}
	if (cost == (*stack_a)->total_cost)
		ft_push_b(stack_a, stack_b);
}

void	a_pos_b_neg(t_node **stack_a, t_node **stack_b, int cost)
{//printf("entra en a_pos_b_neg\n");
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

void	end_move(t_node **stack_a)
{
	int		len;
	t_node	*a;

	a = *stack_a;
	len = count_nodes(a);
	//printf("entra\n");
	//printf("len = %i\n", len);
	while (a && a->idx != 1)
		a = a->next;
	//printf("pos = %i\n", a->pos);
	if (a->pos > len / 2)
	{
		len *= 2;
		while (a->pos < len / 2)
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

t_node *order(t_node **stack_a, t_node **stack_b)
{
	t_node	*b = *stack_b;
	t_node *a = *stack_a;
	int lower;

	while (b)
	{
		lower = lower_cost(&b);
		printf("-----bbbbbbbbb----\n");
		print_stack(b);
		printf("idx = %i b = %i, a = %i target = %i\n", b->idx, b->cost_b, b->cost_a, b->target);
		printf("-----aaaaaaaaa-----\n");
		print_stack(a);
		recalculate(&a, &b);
		printf("idx = %i b = %i, a = %i traget = %i\n", b->idx, b->cost_b, b->cost_a, b->target);
		if (b->cost_b >= 0 && b->cost_a >= 0)
			a_b_pos(&a, &b);
		else if (b->cost_b < 0 && b->cost_a < 0)
			a_b_neg(&a, &b, lower);
		else if (b->cost_b >= 0 && b->cost_a < 0)
			a_neg_b_pos(&a, &b, lower);
		else if (b->cost_b < 0 && b->cost_a >= 0)
			a_pos_b_neg(&a, &b, lower);
		// printf("-----push---b--\n");
		// print_stack(b);
		// printf("-----push---a---\n");
		// print_stack(a);
		// printf("--------------------------------------------\n");
	}
	ft_get_pos((a));
	end_move(&a);
	printf("-----a-----------\n");
	print_stack(a);
	printf("-----b-----------\n");
	print_stack(b);
	return (a);
}

