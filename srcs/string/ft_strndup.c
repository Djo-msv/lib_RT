
#include "lib_rt.h"

char	*ft_strndup(const char *s, size_t size)
{
	char	*result;
	int		i;

	i = 0;
	if (size > ft_strlen(s))
		size = ft_strlen(s);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
