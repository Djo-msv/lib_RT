
#include "lib_rt.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*str;

	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	result = str;
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	return (result);
}
