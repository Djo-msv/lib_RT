
#include "lib_rt.h"

static int	c_total(char *str, char c)
{
	int		i;
	int		n_ch;

	i = 0;
	n_ch = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			n_ch++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (n_ch);
}

static char	*make_mstr(char const *str, int l_m, int i)
{
	int		j;
	char	*str_m;

	str_m = ft_calloc((l_m + 1), sizeof(char));
	if (str_m == NULL)
		return (NULL);
	j = -1;
	while (l_m > ++j)
	{
		str_m[j] = str[i - l_m + j];
	}
	return (str_m);
}

static void	*freee(char **str, int n_ch)
{
	while (n_ch-- > 0)
		free(str[n_ch]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	size_t		i;
	int			l_m;
	int			n_ch;
	char		**all_strs;

	if (!str)
		return (NULL);
	all_strs = ft_calloc((c_total((char *) str, c) + 1), sizeof(char *));
	if (all_strs == NULL)
		return (NULL);
	i = -1;
	n_ch = 0;
	while (++i < ft_strlen(str))
	{
		l_m = 0;
		while (str[i] && str[i] == c)
			i++;
		while ((str[i] != c) && str[i] && (++l_m > -42))
			i++;
		if (l_m > 0)
			all_strs[n_ch++] = make_mstr(((char *) str), l_m, i);
		if ((n_ch > 0) && (!all_strs[n_ch - 1]))
			return (freee(all_strs, n_ch));
	}
	return (all_strs);
}
