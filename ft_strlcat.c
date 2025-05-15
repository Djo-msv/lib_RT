/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:57:07 by nrolland          #+#    #+#             */
/*   Updated: 2024/10/21 20:17:44 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l_d;
	size_t	l_s;

	i = 0;
	if (!dest && !size)
		return (ft_strlen(src));
	l_d = ft_strlen(dest);
	l_s = ft_strlen(src);
	if (size <= l_d)
		return (size + l_s);
	while (src[i] && (l_d + i) < (size - 1))
	{
		dest[l_d + i] = src[i];
		i++;
	}
	dest[l_d + i] = '\0';
	return (l_d + l_s);
}
