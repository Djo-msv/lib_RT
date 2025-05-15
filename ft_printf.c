/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:03:27 by nrolland          #+#    #+#             */
/*   Updated: 2024/11/13 18:35:43 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(const char *form, va_list ap, int i)
{
	if (form[i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (form[i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (form[i] == 'p')
		return (ft_base_hexa(va_arg(ap, unsigned long), 0));
	if (form[i] == 'd' || form[i] == 'i')
		return (ft_putnbr(va_arg(ap, int), 0));
	if (form[i] == 'u')
		return (ft_unsign_putnbr(va_arg(ap, unsigned int), 0));
	if (form[i] == 'x')
		return (ft_base_hexa_upper_lower(va_arg(ap, unsigned int), 0, 0));
	if (form[i] == 'X')
		return (ft_base_hexa_upper_lower(va_arg(ap, unsigned int), 1, 0));
	if (form[i] == '%')
	{
		write(1, &form[i], 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *form, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		len;

	i = -1;
	len = ft_strlen(form);
	count = 0;
	va_start(ap, form);
	while (++i < len)
	{
		if (form[i] == '%')
		{
			count += ft_format(form, ap, ++i);
			if (!form[i])
				count = -1;
		}
		else
		{
			write(1, &form[i], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
