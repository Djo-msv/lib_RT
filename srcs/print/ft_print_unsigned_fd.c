/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:15:28 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:15:30 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

int	ft_print_unsigned_fd(int fd, unsigned int n)
{
	char	*s;
	int		count;

	s = ft_ltoa(n);
	count = ft_print_str_fd(fd, s);
	free(s);
	return (count);
}
