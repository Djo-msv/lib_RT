
int	ft_isdigit(char caract)
{
	if (caract >= '0' && caract <= '9')
		return (1);
	else
		return (0);
}

int	ft_strisdigit(char *str)
{
	while (str && *str)
	{
		if (!ft_isdigit(*str++))
			return (1);
	}
	return (0);
}
