/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:29:31 by nrolland          #+#    #+#             */
/*   Updated: 2024/10/15 17:59:45 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	int		valid;
	int		to_find_len;

	i = 0;
	to_find_len = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return ((char *)str);
	while ((len > i) && str[i])
	{
		if (i + to_find_len > len)
			return (0);
		j = -1;
		valid = 1;
		while (to_find[++j])
		{
			if (str[i + j] != to_find[j])
				valid = 0;
		}
		if (valid == 1)
			return (((char *)str) + i);
		i++;
	}
	return (0);
}
