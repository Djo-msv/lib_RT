
#include "lib_rt.h"

char	*ft_lutoa_base(unsigned long long n, char *base)
{
	char				*buffer;
	char				*temp;
	unsigned long long	len_base;

	len_base = (unsigned long long) ft_strlen(base);
	buffer = ft_calloc((63 + 1), sizeof(char));
	if (n >= len_base)
	{
		temp = ft_lutoa_base(n / len_base, base);
		buffer = ft_strcat(buffer, temp);
		free(temp);
	}
	buffer[ft_strlen(buffer)] = base[n % len_base];
	buffer[ft_strlen(buffer)] = '\0';
	return (buffer);
}
