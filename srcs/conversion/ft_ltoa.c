
#include "lib_rt.h"

static int	sizeofn(long n, char *pnt, int len)
{
	int	l;

	l = 0;
	if (pnt)
		pnt[len--] = '\0';
	while (n >= 10)
	{
		if (pnt)
			pnt[len--] = (char)(n % 10 + '0');
		n = n / 10;
		l++;
	}
	if (pnt)
		pnt[len] = (char)((n % 10) + '0');
	return (l);
}

char	*ft_ltoa(long n)
{
	long long	num;
	int				len;
	int				negate;
	char			*result;

	negate = 0;
	if (n < 0)
	{
		negate = 1;
		n = n * -1;
	}
	num = (unsigned int)n;
	len = sizeofn(num, NULL, 0) + 1 + negate;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (negate)
		result[0] = '-';
	sizeofn(num, result, len);
	return (result);
}
