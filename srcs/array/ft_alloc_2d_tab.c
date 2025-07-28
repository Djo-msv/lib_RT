/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_2d_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:19:20 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:20:45 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

char	**ft_alloc_2d_tab(int x, int y)
{
	int		i;
	char	**result;

	result = ft_calloc(x + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i != x)
	{
		result[i] = ft_calloc(y + 1, sizeof(char));
		if (!result[i])
		{
			while (i-- != 0)
				free(result[i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
