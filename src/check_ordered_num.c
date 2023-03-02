/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ordered_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:38:48 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/02 15:33:17 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_number(t_node **lst)
{
	t_node	*aux;

	aux = *lst;
	while (aux->next)
	{
		if (aux->next->value < aux->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	sort_number2(t_node **lst)
{
	int		i;
	t_node	*a;

	a = *lst;
	i = 1;
	while (a->next)
	{
		if (a->value > a->next->value)
			i = 0;
		a = a->next;
	}
	return (i);
}

/**
 * @brief Si solo se pasan dos numeros comprueba si estan ordenados y si 
 * es asi para el programa
 * 
 * @param stack
 */
void	ordered_number(t_node **stack)
{
	if ((*stack)->value < (*stack)->next->value)
		exit (0);
	else
	{
		ft_move_swap_a(stack, 0);
		exit (0);
	}
}

void	minus_number(t_node **stack, int count)
{
	is_repeat_nbr(*stack);
	if (count < 2)
		exit (0);
	else if (count < 3)
		ordered_number(stack);
}
