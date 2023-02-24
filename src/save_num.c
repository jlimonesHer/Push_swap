/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:22:31 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/24 19:35:42 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief cuenta el numero de entradas si solo hay un argumento
 * 
 * @param argc numero de argumentos
 * @return int el numero de argumentos que se han pasado.
 */
int	ft_count_num(char **params)
{
	int		count;

	count = 0;
	while (params[count])
		count++;
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
	int			i;

	i = 0;
	node_a = NULL;
	while (i < argc - 1)
	{
		control_atoi(params[i]);
		ft_push(&node_a, ft_atoi(params[i]), 0);
		free(params[i]);
		i++;
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
		ft_push(&node_a, ft_atoi(params[argc]), 0);
		argc--;
	}
	return (node_a);
}
