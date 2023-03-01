/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:09 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/01 13:25:46 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../src/push_swap.h"

static const char	*ft_prep(const char *str, int *isneg)
{
	*isneg = 1;
	while (((*str > 8 && *str < 14) || *str == ' '))
		str++;
	if (*str == '-')
	{
		*isneg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int			isneg;
	int			ret;

	ret = 0;
	str = ft_prep(str, &isneg);
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += *str++ - '0';
	}
	ret *= isneg;
	if (isneg == -1 && ret > 0)
		std_error("Error");
	if (isneg == 1 && ret < 0)
		std_error("Error");
	return (ret);
}
