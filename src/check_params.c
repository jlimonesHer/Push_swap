/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:23:05 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 11:06:09 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief verifica  si un es numero o signo.
 * 
 * @param param recibe el caracter.
 * @return int 0 si no es numero o signo, 1 si lo es.
 */
int	is_num_or_signed(char param)
{
	if ((param >= '0' && param <= '9')
		|| (param == '-' || param == '+'))
		return (1);
	return (0);
}

/**
 * @brief verifica qeu los parametros no tengan cararcteres no deseados ni
 * signos inesperados
 * 
 * @param argc numero de argumentos
 * @param param argumentos pasados al programa
 * @return int 1 si los parametros son correctos o 0 si no lo son
 */
int	check_param_num(int argc, char **params)
{
	int	i;

	argc--;
	while (argc >= 1)
	{
		i = 0;
		while (params[argc][i])
		{
			if (!is_num_or_signed(params[argc][i]))
				help_argv_validate("Argumentos no validos.");
			if ((params[argc][i] == '-' || params[argc][i] == '+')
				&& i > 0)
				help_argv_validate("Argumentos no validos.");
			i++;
		}
		argc--;
	}
	return (1);
}

/**
 * @brief funcion para guardar en una matriz en caso de que 
 * solo pasen 1 parametro.
 * 
 * @param params string del parametro 1
 * @return char** matriz de ls parametro separado en strings
 */
char	**split_for_param(char *params)
{
	char	**split_param;
	int		len;

	len = 0;
	split_param = ft_split(params, ' ');
	while (split_param[len] != NULL)
		len++;
	if (!check_param_num(len, split_param))
		return (0);
	return (split_param);
}

/**
 * @brief comprueba que no haya numeros repetidos
 * 
 * @param node_a recibe la pila de numeros
 * @return int 
 */
int	is_repeat_nbr(t_node *node)
{
	t_node	*tmp;

	while (node != NULL)
	{
		tmp = node;
		while (node->next != NULL)
		{
			if (tmp->value == node->next->value)
				return (0);
			else
				node = node->next;
		}
		node = tmp;
		node = node->next;
	}
	return (1);
}

/**
 * @brief Comprueba que un numero no salga del rango de enteros
 * 
 * @param n numero a comprobar
 */
void	control_atoi(char *n)
{
	if (ft_atoi(n) > INT_MAX || ft_atoi(n) < INT_MIN)
		std_error("Solo se pueden tratar numeros enteros");
}
