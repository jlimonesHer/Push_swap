/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:22:31 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/11 12:48:32 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_node **node, t_node **dst)
{
	t_node	*a;

	a = *dst;
	ft_push(node, a->value, a->idx, a->pos);
	*dst = a->next;
	free(a);
}

/**
 * @brief cuenta el numero de entradas si solo hay un argumento
 * 
 * @param argc numero de argumentos
 * @return int el numero de argumentos que se han pasado.
 */
int	ft_count_num(char *params)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (params[i])
	{
		if (!is_num_or_signed(params[i]))
			count++;
		i++;
	}
	return (count);
}

/**
 * @brief convirte la matriz en una lista de nodos
 * 
 * @param argc numero de argumentos
 * @param params argumentos
 * @return t_node* lista iniciada con valores
 */
t_node	*save_matrix_node_a(int argc, char **params)
{
	t_node		*node_a;

	node_a = NULL;
	while (argc >= 0)
	{
		control_atoi(params[argc]);
		ft_push(&node_a, ft_atoi(params[argc]),0,0);
		free(params[argc]);
		argc--;
	}
	return (node_a);
}

/**
 * @brief convirte llos argumentos en una lista de nodos
 * 
 * @param argc numero de argumentos
 * @param params argumentos
 * @return t_node* lista iniciada con valores
 */
t_node	*save_param_node_a(int argc, char **params)
{
	t_node		*node_a;

	node_a = NULL;
	argc--;
	while (argc >= 1)
	{
		control_atoi(params[argc]);
		ft_push(&node_a, ft_atoi(params[argc]), 0, 0);
		argc--;
	}
	return (node_a);
}
