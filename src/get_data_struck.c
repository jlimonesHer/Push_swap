/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_struck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:53:57 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 20:25:33 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Cuenta los nodos de una lista
 * 
 * @param list lista de strucks
 * @return int 
 */
static int	count_nodes(t_node *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

/**
 * @brief Asigna la posicion inicial a cada nodo
 * 
 * @param node pila inicial
 */
void	ft_get_pos(t_node *nodes)
{
	t_node		*tmp;
	int			i;

	i = 1;
	tmp = nodes;
	while (nodes)
	{
		nodes->pos = i;
		i++;
		nodes = nodes->next;
	}
	nodes = tmp;
}

/**
 * @brief Devuelve la lista al orden inicial
 * Se ordena segun pos asignada previamente con ft_get_pos();
 * 
 * @param node pila inicial
 */
void	back_pos(t_node **nodes)
{
	t_node	*ptr;
	int		i;

	ptr = *nodes;
	i = count_nodes(*nodes);
	while (count_nodes(*nodes) >= i)
	{
		while (ptr->next != NULL)
		{
			if (ptr->pos < ptr->next->pos)
				ptr = ptr->next;
			else
			{
				ft_swap(&ptr->value, &ptr->next->value);
				ft_swap(&ptr->idx, &ptr->next->idx);
				ft_swap(&ptr->pos, &ptr->next->pos);
				i = 0;
			}
		}
		ptr = *nodes;
		i++;
	}
}

/**
 * @brief Asigna el index a cada nodo de menor a mayor.
 * 
 * @param nodes nodos de la lista.
 * @param count numero de nodos de la lista.
 */
static	void	fill_idx(t_node **nodes, int count)
{
	int			i;
	t_node		*ptr;

	ptr = *nodes;
	i = 0;
	while (i < count)
	{
		ptr->idx = ++i;
		ptr = ptr->next;
	}
}

/**
 * @brief Ordena los nodos por valor de menor a mayor.
 * 
 * @param node nodos de la lista.
 */
void	ft_get_idx(t_node **node)
{
	t_node	*ptr;
	int		i;

	ptr = *node;
	i = count_nodes(*node);
	while (count_nodes(*node) >= i)
	{
		while (ptr->next != NULL)
		{
			if (ptr->value < ptr->next->value)
				ptr = ptr->next;
			else
			{
				ft_swap(&ptr->value, &ptr->next->value);
				ft_swap(&ptr->pos, &ptr->next->pos);
				i = 0;
			}
		}
		ptr = *node;
		i++;
	}
	fill_idx(&ptr, count_nodes(ptr));
	back_pos(&ptr);
}
