/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:19:40 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:19:43 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static int	handel_sign(char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

float	ft_atof(char *str)
{
	int		int_part;
	int		div;
	int		sign;
	float	frac;

	int_part = 0;
	div = 10;
	frac = 0.0f;
	sign = handel_sign(str);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str != '.')
	{
		if (*str < '0' || *str > '9' || int_part < 0)
			return (0);
		int_part = int_part * 10 + (*str++ - '0');
	}
	if (*str == '.')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		frac += (float)(*str++ - '0') / div;
		div *= 10;
	}
	return ((int_part + frac) * sign);
}
