/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: star <star@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:15:19 by star              #+#    #+#             */
/*   Updated: 2025/07/28 16:15:22 by star             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

int	ft_print_integer_fd(int fd, int n)
{
	char	*s;
	int		count;

	s = ft_itoa(n);
	count = ft_print_str_fd(fd, s);
	free(s);
	return (count);
}
