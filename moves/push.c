/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 08:31:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/11 08:50:05 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ft_push_a(t_node **node, t_node **dst, char stack)
{
	t_node	*a;

	a = *dst;
	ft_push(node, a->value, a->idx, a->pos);
	*dst = a->next;
	free(a);
	if (stack == 'a')
		printf("pa\n");
	if (stack == 'a')
		printf("pb\n");
}

