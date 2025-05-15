/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:21:24 by nrolland          #+#    #+#             */
/*   Updated: 2024/11/13 18:36:50 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_hexa(unsigned long n, char *base, int count)
{
	if (n > 15)
	{
		count = f_hexa(n / 16, base, count);
		count = f_hexa(n % 16, base, count);
	}
	else
	{
		count++;
		write(1, &base[n], 1);
	}
	return (count);
}

int	ft_base_hexa(unsigned long n, int count)
{
	if (!n)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	return (f_hexa(n, "0123456789abcdef", count));
}

int	ft_base_hexa_upper_lower(unsigned int n, int verif, int count)
{
	if (verif == 0)
		return (count = f_hexa(n, "0123456789abcdef", count));
	else
		return (count = f_hexa(n, "0123456789ABCDEF", count));
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		count = ft_putchar('-');
		count = ft_putnbr(n * -1, count);
	}
	else if (n > 9)
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	else if (n < 10)
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_unsign_putnbr(unsigned int n, int count)
{
	if (n > 9)
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	else if (n < 10)
		count += ft_putchar(n + 48);
	return (count);
}
