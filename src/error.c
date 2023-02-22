/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:48:14 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/21 13:26:42 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief muestra el error y mensaje de ayuda para argumentos no validos.
 * 
 * @param error 
 */
void	help_argv_validate(char *error)
{
	ft_putstr_fd(error, 2);
	ft_printf("\n");
	ft_printf("Help:\n");
	ft_printf("	[./push_swap n n n]\n");
	ft_printf("	[./push_swap \"n n n\"]\n");
	ft_printf("	[./push_swap \"n\" \"n\" \"n\"]\n");
	exit(-1);
}

/**
 * @brief Funcion para salida de error estandar.
 * 
 * @param error recibe la cadena a mostrar.
 */
void	std_error(char *error)
{
	ft_putstr_fd(error, 2);
	ft_printf("\n");
	exit(-1);
}

void	print(t_node *s)
{
	while (s)
	{
		ft_printf("%i ", s->value);
		s = s->next;
	}
	ft_printf("\n");
}
