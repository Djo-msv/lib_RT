/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrolland <nrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:22:58 by star              #+#    #+#             */
/*   Updated: 2025/05/20 18:22:20 by nrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static int	is_op(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(char *str, char *sep, int len)
{
	int	i;
	int	n_str;
	int	count;

	count = 0;
	n_str = 0;
	i = 0;
	while (len > i)
	{
		count = 0;
		while (str[i] && is_op(str[i], sep))
			i++;
		while (str[i] && !is_op(str[i], sep))
		{
			i++;
			count++;
		}
		if (count > 0)
			n_str++;
	}
	return (n_str);
}

static int	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i++]);
	}
	free(str);
	return (1);
}

static int	split(char *str, char *sep, int len, char **all)
{
	int	i;
	int	j;
	int	len_arg;

	i = 0;
	j = 0;
	len_arg = 0;
	while (len > i)
	{
		len_arg = 0;
		while (str[i] && is_op(str[i], sep))
			i++;
		while (str[i] && !is_op(str[i], sep))
		{
			i++;
			len_arg++;
		}
		if (len_arg > 0)
		{
			all[j] = ft_substr(str, i - len_arg, len_arg);
			if (!all[j++])
				return (ft_free(all));
		}
	}
	return (0);
}

char	**ft_split(char *str, char *sep)
{
	char	**all;
	int		len;

	if (!str || !sep)
		return (NULL);
	len = ft_strlen(str);
	all = ft_calloc(ft_count(str, sep, len) + 1, sizeof(char *));
	if (!all)
		return (NULL);
	if (split(str, sep, len, all))
		return (NULL);
	return (all);
}
