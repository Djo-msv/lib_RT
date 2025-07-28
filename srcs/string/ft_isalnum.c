/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:16:07 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:21:24 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char chr)
{
	if ((chr >= '0' && chr <= '9') || ((chr >= 'a' && chr <= 'z')
			|| (chr >= 'A' && chr <= 'Z')))
		return (1);
	else
		return (0);
}

int	ft_strisalnum(char *string)
{
	while (string && *string)
	{
		if (!ft_isalnum(*string++))
			return (1);
	}
	return (0);
}
