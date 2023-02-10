/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:58:14 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 20:11:26 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_swap(t_node **first)
{
	t_node	*tmp;

	tmp = (*first)->next;
	(*first)->next = (*first)->next->next;
	tmp->next = (*first);
	(*first) = tmp;
}
