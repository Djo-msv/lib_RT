/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:23:34 by nrolland          #+#    #+#             */
/*   Updated: 2024/10/21 17:21:39 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		l_start;
	int		len;
	int		i;

	l_start = 0;
	i = -1;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (verif(s1[l_start], set))
		l_start++;
	while (verif(s1[len - 1], set))
		len--;
	if (len - l_start <= 0)
		return (ft_strdup(""));
	new_str = ft_calloc((len - l_start + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (l_start < len)
	{
		new_str[++i] = s1[l_start];
		l_start++;
	}
	return (new_str);
}
