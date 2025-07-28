/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:20:01 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:20:03 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atoui(const char *nptr)
{
	int			i;
	long long	r;

	i = 0;
	r = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == 45)
		return (0);
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((r * 10) + (nptr[i] - '0') <= r && r != 0)
			return (0);
		else if (r != 0 && (r * 10) + (nptr[i] - '0') <= r)
			return (-1);
		r = (r * 10) + (nptr[i++] - '0');
	}
	return ((unsigned int)r);
}
