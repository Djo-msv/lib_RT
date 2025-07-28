/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:16:27 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:16:30 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char caract)
{
	if (caract >= '0' && caract <= '9')
		return (1);
	else
		return (0);
}

int	ft_strisdigit(char *str)
{
	while (str && *str)
	{
		if (!ft_isdigit(*str++))
			return (1);
	}
	return (0);
}
