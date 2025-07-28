/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:16:58 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:21:54 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

char	*ft_strjoinfree(char *s1, char *s2, int mode)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (result);
}
