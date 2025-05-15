/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:57:46 by nrolland          #+#    #+#             */
/*   Updated: 2025/03/24 15:06:46 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	return (dest);
}

static void	ft_free(int f, char *s1, char *s2)
{
	if ((f == 1 || f == 3) && s1)
		free(s1);
	if ((f == 2 || f == 3) && s2)
		free(s2);
}

char	*ft_strjoin(char *s1, char *s2, int f)
{
	char	*new_str;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		new_str = ft_strdup(s2);
		ft_free(f, s1, s2);
		return (new_str);
	}
	if (!s2)
	{
		new_str = ft_strdup(s1);
		ft_free(f, s1, s2);
		return (new_str);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_calloc((len + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	new_str = ft_strcat(new_str, s1);
	new_str = ft_strcat(new_str, s2);
	ft_free(f, s1, s2);
	return (new_str);
}
