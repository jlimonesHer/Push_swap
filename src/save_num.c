/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:22:31 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 12:12:47 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief esta funcion creara un nuevo nodo al principio de la lista
 * 
 * @param node recibe un puntero al puntero de la lista
 * @param num el entero a guardar,
 */
void	ft_push(t_node **node, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!node)
		std_error("Algo salio mal al reservar memoria");
	new_node->value = num;
	new_node->next = *node;
	*node = new_node;
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
		ft_push(&node_a, ft_atoi(params[argc]));
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
		ft_push(&node_a, ft_atoi(params[argc]));
		argc--;
	}
	return (node_a);
}
