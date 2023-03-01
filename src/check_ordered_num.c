/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ordered_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:38:48 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/01 15:15:36 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Si solo se pasan dos numeros comprueba si estan ordenados y si 
 * es asi para el programa
 * 
 * @param stack
 */
void	ordered_number(t_node **stack)
{
	if ((*stack)->value < (*stack)->next->value)
		exit (-1);
	else
	{
		ft_move_swap_a(stack, 0);
		exit (-1);
	}
}

void	minus_number(t_node **stack, int count)
{
	is_repeat_nbr(*stack);
	if (count < 2)
		exit (-1);
	else if (count < 3)
		ordered_number(stack);
}
