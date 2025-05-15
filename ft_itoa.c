/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:29:02 by nrolland          #+#    #+#             */
/*   Updated: 2024/10/21 15:19:30 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_m(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	len = len_m(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if ((n < 0) && (i++ > -42))
		str[0] = '-';
	if (n < 0)
		n *= -1;
	len -= 1;
	while (len >= i)
	{
		str[len--] = (n % 10 + 48);
		n /= 10;
	}
	return (str);
}
