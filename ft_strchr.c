/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:35:53 by nrolland          #+#    #+#             */
/*   Updated: 2024/10/21 17:08:45 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	check;

	i = 0;
	check = c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == check)
			return (str + i);
		i++;
	}
	if (str[i] != check)
		return (0);
	return (str + i);
}
