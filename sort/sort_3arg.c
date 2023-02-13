/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:27 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/13 07:22:25 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **stack_a)
{
	if (((*stack_a)->idx == 1) && ((*stack_a)->next->idx == 2))
		return ;
	else if (((*stack_a)->idx == 1) && ((*stack_a)->next->idx == 3))
	{
		reverse_rotate_a(stack_a, 0);
		ft_move_swap_a(stack_a, 0);
	}
	else if (((*stack_a)->idx == 2) && ((*stack_a)->next->idx == 1))
		ft_move_swap_a(stack_a, 0);
	else if (((*stack_a)->idx == 2) && ((*stack_a)->next->idx == 3))
		reverse_rotate_a(stack_a, 0);
	else if (((*stack_a)->idx == 3) && ((*stack_a)->next->idx == 1))
		rotate_a(stack_a, 0);
	else if (((*stack_a)->idx == 3) && ((*stack_a)->next->idx == 2))
	{
		rotate_a(stack_a, 0);
		ft_move_swap_a(stack_a, 0);
	}
}
