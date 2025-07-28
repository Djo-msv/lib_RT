/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:15:15 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:15:17 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

int	ft_print_hexa_fd(int fd, unsigned long long n, int is_upper)
{
	char	*s;
	int		count;

	if (is_upper)
		s = ft_lutoa_base(n, "0123456789ABCDEF");
	else
		s = ft_lutoa_base(n, "0123456789abcdef");
	count = ft_print_str_fd(fd, s);
	free(s);
	return (count);
}
