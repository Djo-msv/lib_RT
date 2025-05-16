
#include "lib_rt.h"

int	ft_print_unsigned_fd(int fd, unsigned int n)
{
	char	*s;
	int		count;

	s = ft_ltoa(n);
	count = ft_print_str_fd(fd, s);
	free(s);
	return (count);
}
