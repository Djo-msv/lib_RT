/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:14:38 by star              #+#    #+#             */
/*   Updated: 2025/10/02 21:01:09 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

int	ft_strchr(char *str, char chr)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == chr)
			return (0);
		i++;
	}
	return (1);
}

void	read_file(char **reserv, int fd)
{
	int		code;
	char	buffer[42];

	while (ft_strchr(*reserv, '\n'))
	{
		code = read(fd, buffer, 42);
		if (code <= 0)
			break ;
		buffer[code] = '\0';
		(*reserv) = ft_strjoinfree((*reserv), buffer, 1);
	}
}

char	*put_reserv_in_line(char *reserv)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	i = 0;
	while (reserv && reserv[i] && reserv[i] != '\n')
		i++;
	len = i + 1;
	result = malloc((len + 1) * sizeof(char));
	j = 0;
	while (j != len)
	{
		result[j] = reserv[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

void	remove_first_line(char **pnt_reserv)
{
	int		i;
	int		j;
	int		len;
	char	*reserv;
	char	*result;

	i = 0;
	if (!pnt_reserv)
		return ;
	reserv = *pnt_reserv;
	while (reserv[i] && reserv[i] != '\n')
		i++;
	if (reserv[i])
		i++;
	len = ft_strlen(reserv) - i;
	result = malloc((len + 1) * sizeof(char));
	j = 0;
	while (reserv[i])
		result[j++] = reserv[i++];
	result[j] = '\0';
	free(reserv);
	*pnt_reserv = result;
}

char	*get_next_line(int fd)
{
	static char	*reserv = NULL;
	char		*line;

	if (fd == -1 && reserv)
	{
		free(reserv);
		return (NULL);
	}
	line = NULL;
	read_file(&reserv, fd);
	if (!reserv)
		return (NULL);
	line = put_reserv_in_line(reserv);
	remove_first_line(&reserv);
	if (!line[0])
	{
		free(reserv);
		reserv = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
