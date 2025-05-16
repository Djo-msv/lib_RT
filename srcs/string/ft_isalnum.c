
int ft_isalnum(char chr)
{
	if ((chr >= '0' && chr <= '9') || ((chr >= 'a' && chr <= 'z')
			|| (chr >= 'A' && chr <= 'Z')))
		return (1);
	else
		return (0);
}


int	ft_strisalnum(char *string)
{
	while (string && *string)
	{
		if (!ft_isalnum(*string++))
			return (1);
	}
	return (0);
}
