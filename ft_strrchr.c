/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:49:53 by nrolland          #+#    #+#             */
/*   Updated: 2024/10/21 17:16:30 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	check;

	check = c;
	str = (char *)s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (str[len] == check)
			return (str + len);
		len--;
	}
	if (str[len] != check)
		return (0);
	return (str + len);
}
