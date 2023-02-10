/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:16:00 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 11:00:52 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param haynode (pajar) string en la que buscar la aguja
 * @param needle (agujar) string que hay que buscar
 * @param n numero de caracteres de needle
 * @return char* 
 */
char	*ft_strnstr(const char *haynode, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
		return ((char *)haynode);
	while (i < n && haynode[i] != '\0')
	{
		j = 0;
		while (i + j < n && haynode[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *)haynode + i);
		i++;
	}
	return (0);
}
