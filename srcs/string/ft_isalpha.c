/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:16:16 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:21:39 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char caract)
{
	if ((caract >= 'a' && caract <= 'z') || (caract >= 'A' && caract <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isstralpha(char *str)
{
	while (str && *str)
	{
		if (!ft_isalpha(*str++))
			return (1);
	}
	return (0);
}
