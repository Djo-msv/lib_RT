/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:32:38 by jmassavi          #+#    #+#             */
/*   Updated: 2025/07/28 16:14:55 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *) src;
	destination = (unsigned char *) dest;
	if (src == NULL && dest == NULL)
		return (dest);
	while (size > 0)
	{
		size--;
		destination[size] = source[size];
	}
	return (dest);
}
